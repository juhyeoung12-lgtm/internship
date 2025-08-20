#ifndef LEG_KILO_ROS_INTERFACE_HPP
#define LEG_KILO_ROS_INTERFACE_HPP

#include <memory>
#include <mutex>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <nav_msgs/msg/path.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include "lidar_processing.h"  // LidarProcessing + common::LidarScan/PointCloudType

// (옵션) Unitree HighState를 구독하려면 주석 해제하고 CMake에 의존성 추가
// #include <unitree_legged_msgs/msg/high_state.hpp>

namespace legkilo {

class RosInterface : public rclcpp::Node {
public:
  explicit RosInterface(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

  // leg_kilo_node.cc에서 호출
  void rosInit(const std::string& config_file);
  void run();

private:
  // Subscribers
  void onPoints(const sensor_msgs::msg::PointCloud2::ConstSharedPtr msg);
  // (옵션) Unitree HighState 구독 사용 시 주석 해제
  // void onHighState(const unitree_legged_msgs::msg::HighState::ConstSharedPtr msg);

  // Publishers/TF
  void publishOdomTF(const rclcpp::Time& stamp);

private:
  // --- ROS comms ---
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_points_;
  // rclcpp::Subscription<unitree_legged_msgs::msg::HighState>::SharedPtr sub_high_state_;

  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_cloud_reg_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_cloud_body_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr           pub_path_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr       pub_odom_;
  std::unique_ptr<tf2_ros::TransformBroadcaster>              tf_broadcaster_;

  // --- Parameters (declare_parameter/get_parameter) ---
  std::string topic_points_;
  std::string topic_high_state_;     // 사용 시
  std::string topic_cloud_reg_;
  std::string topic_cloud_body_;
  std::string topic_path_;
  std::string topic_odom_;
  std::string frame_map_;
  std::string frame_base_;

  // --- Lidar processing ---
  LidarProcessing::Config          lp_cfg_;
  std::unique_ptr<LidarProcessing> lidar_proc_;

  // --- State/path (임시: ESKF 연결 전 기본값) ---
  Eigen::Isometry3d pose_{Eigen::Isometry3d::Identity()};
  Eigen::Vector3d    vel_{Eigen::Vector3d::Zero()};
  nav_msgs::msg::Path path_msg_;

  // --- Last input messages ---
  sensor_msgs::msg::PointCloud2::ConstSharedPtr last_points_msg_;
  // unitree_legged_msgs::msg::HighState last_high_state_;

  // --- Sync ---
  std::mutex mutex_;
};

} // namespace legkilo

#endif // LEG_KILO_ROS_INTERFACE_HPP

