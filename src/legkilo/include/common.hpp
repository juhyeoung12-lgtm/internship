#ifndef LEG_KILO_COMMON_HPP
#define LEG_KILO_COMMON_HPP

#include <deque>
#include <memory>
#include <vector>
#include <cmath>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

// ROS2 messages
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

namespace legkilo {
namespace common {

// ===== Point / Cloud types =====
using PointType      = pcl::PointXYZINormal;
using PointCloudType = pcl::PointCloud<PointType>;
using CloudPtr       = PointCloudType::Ptr;        // PCL shared_ptr
using CloudConstPtr  = PointCloudType::ConstPtr;   // PCL shared_ptr

// ===== LiDAR scan bundle =====
//  - cloud_: p.curvature 에 스캔 내 "상대시간(초)" 저장 (lidar_processing.cc와 합의)
struct LidarScan {
  double   lidar_begin_time_ = 0.0;  // [s]
  double   lidar_end_time_   = 0.0;  // [s]
  CloudPtr cloud_;
};

// ===== Kinematics + IMU fused measurement =====
// leg order: FR, FL, RR, RL
struct KinImuMeas {
  double time_stamp_ = 0.0;  // [s] (rclcpp::Time(...).seconds())
  double acc_[3]  {0.0, 0.0, 0.0};
  double gyr_[3]  {0.0, 0.0, 0.0};
  double foot_pos_[4][3] {{0}};   // per leg xyz
  double foot_vel_[4][3] {{0}};   // per leg xyz
  bool   contact_[4] {false, false, false, false}; // optional
};

// ===== Mixed measurement group (필요 시 사용) =====
struct MeasGroup {
  LidarScan                                      lidar_scan_;
  std::deque<sensor_msgs::msg::Imu::SharedPtr>   imus_;      // ROS2 Imu ptr
  std::deque<KinImuMeas>                         kin_imus_;
};

enum class LidarType { VEL = 1, OUSTER = 2 };

} // namespace common
} // namespace legkilo

#endif // LEG_KILO_COMMON_HPP

