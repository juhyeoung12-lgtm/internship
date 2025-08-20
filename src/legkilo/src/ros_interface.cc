#include "ros_interface.h"

#include <pcl_conversions/pcl_conversions.h>

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>

#include <tf2_ros/transform_broadcaster.h>

#include "common.hpp"
#include "lidar_processing.h"
#include "glog_utils.hpp"

namespace legkilo {

using std::placeholders::_1;

RosInterface::RosInterface(const rclcpp::NodeOptions& options)
: rclcpp::Node("legkilo", options)
{
  // -----------------------------
  // Parameters
  // -----------------------------
  topic_points_      = this->declare_parameter<std::string>("topic_points", "/agent1/ouster/points");
  topic_high_state_  = this->declare_parameter<std::string>("topic_high_state", "/high_state");
  topic_cloud_reg_   = this->declare_parameter<std::string>("topic_cloud_registered", "/cloud_registered");
  topic_cloud_body_  = this->declare_parameter<std::string>("topic_cloud_registered_body", "/cloud_registered_body");
  topic_path_        = this->declare_parameter<std::string>("topic_path", "/path");
  topic_odom_        = this->declare_parameter<std::string>("topic_odom", "/Odomtry");

  frame_map_         = this->declare_parameter<std::string>("frame_map", "map");
  frame_base_        = this->declare_parameter<std::string>("frame_base", "base_link");

  lp_cfg_.filter_num_       = this->declare_parameter<int>("lidar.filter_num", 1);
  lp_cfg_.time_scale_       = this->declare_parameter<double>("lidar.time_scale", 1e-9); // ns→s
  lp_cfg_.voxel_leaf_size_  = this->declare_parameter<double>("lidar.voxel_leaf_size", 0.0);
  lp_cfg_.min_range_        = this->declare_parameter<double>("lidar.min_range", 0.0);
  lp_cfg_.max_range_        = this->declare_parameter<double>("lidar.max_range", 0.0);

  // -----------------------------
  // Publishers / Subscriptions
  // -----------------------------
  auto qos_sensor  = rclcpp::SensorDataQoS();
  auto qos_default = rclcpp::QoS(rclcpp::KeepLast(10));

  pub_cloud_reg_  = this->create_publisher<sensor_msgs::msg::PointCloud2>(topic_cloud_reg_,  qos_default);
  pub_cloud_body_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(topic_cloud_body_, qos_default);
  pub_path_       = this->create_publisher<nav_msgs::msg::Path>(topic_path_, qos_default);
  pub_odom_       = this->create_publisher<nav_msgs::msg::Odometry>(topic_odom_, qos_default);

  sub_points_     = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      topic_points_, qos_sensor, std::bind(&RosInterface::onPoints, this, _1));

  tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

  // -----------------------------
  // Helpers
  // -----------------------------
  lidar_proc_ = std::make_unique<LidarProcessing>(lp_cfg_);

  path_msg_.header.frame_id = frame_map_;
  pose_.setIdentity();
  vel_.setZero();

  LOG(INFO) << "RosInterface constructed (ROS2)";
}

void RosInterface::rosInit(const std::string& /*config_file*/)
{
  // 필요 시 YAML 파일/기타 설정 로드 지점
  // 현재는 파라미터만 사용
}

void RosInterface::onPoints(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg)
{
  std::lock_guard<std::mutex> lk(mutex_);
  last_points_msg_ = msg;
}

void RosInterface::run()
{
  sensor_msgs::msg::PointCloud2::ConstSharedPtr points_msg;
  {
    std::lock_guard<std::mutex> lk(mutex_);
    points_msg = last_points_msg_;
  }
  if (!points_msg) return;

  // LiDAR 처리 (다운샘플/상대시간(curvature))
  common::LidarScan scan;
  lidar_proc_->ousterHandler(points_msg, scan);

  // === TODO: 여기에 ESKF/맵 업데이트 호출 연결 ===
  //  예:
  //  eskf_.predict(...);
  //  eskf_.updateLidar(scan);
  //  pose_ = eskf_.statePose();
  //  vel_  = eskf_.stateVel();
  //
  //  또는 voxel_map_.insert(scan.cloud_, pose_);
  // ==============================================

  // (임시) 등록 클라우드 발행: map, body 프레임
  sensor_msgs::msg::PointCloud2 cloud_msg;
  pcl::toROSMsg(*scan.cloud_, cloud_msg);
  cloud_msg.header.stamp = points_msg->header.stamp;

  cloud_msg.header.frame_id = frame_map_;
  pub_cloud_reg_->publish(cloud_msg);

  cloud_msg.header.frame_id = frame_base_;
  pub_cloud_body_->publish(cloud_msg);

  // Odom/TF/Path 발행
  publishOdomTF(points_msg->header.stamp);
}

void RosInterface::publishOdomTF(const rclcpp::Time& stamp)
{
  // pose_ : Eigen::Isometry3d, vel_ : Eigen::Vector3d
  const Eigen::Matrix3d R = pose_.rotation();
  const Eigen::Vector3d t = pose_.translation();
  const Eigen::Quaterniond q(R);

  // TF
  geometry_msgs::msg::TransformStamped tf;
  tf.header.stamp = stamp;
  tf.header.frame_id = frame_map_;
  tf.child_frame_id  = frame_base_;
  tf.transform.translation.x = t.x();
  tf.transform.translation.y = t.y();
  tf.transform.translation.z = t.z();
  tf.transform.rotation.x = q.x();
  tf.transform.rotation.y = q.y();
  tf.transform.rotation.z = q.z();
  tf.transform.rotation.w = q.w();
  tf_broadcaster_->sendTransform(tf);

  // Odom
  nav_msgs::msg::Odometry odom;
  odom.header = tf.header;
  odom.child_frame_id = frame_base_;
  odom.pose.pose.position.x = t.x();
  odom.pose.pose.position.y = t.y();
  odom.pose.pose.position.z = t.z();
  odom.pose.pose.orientation = tf.transform.rotation;
  odom.twist.twist.linear.x = vel_.x();
  odom.twist.twist.linear.y = vel_.y();
  odom.twist.twist.linear.z = vel_.z();
  odom.twist.twist.angular.x = 0.0;
  odom.twist.twist.angular.y = 0.0;
  odom.twist.twist.angular.z = 0.0;
  pub_odom_->publish(odom);

  // Path
  geometry_msgs::msg::PoseStamped ps;
  ps.header = odom.header;
  ps.pose   = odom.pose.pose;
  path_msg_.header.stamp = stamp;
  path_msg_.poses.push_back(ps);
  pub_path_->publish(path_msg_);
}

} // namespace legkilo


