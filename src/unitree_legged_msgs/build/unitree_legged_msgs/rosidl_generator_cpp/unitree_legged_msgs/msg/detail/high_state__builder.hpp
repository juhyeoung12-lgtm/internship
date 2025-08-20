// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/HighState.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/high_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_HighState_crc
{
public:
  explicit Init_HighState_crc(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::HighState crc(::unitree_legged_msgs::msg::HighState::_crc_type arg)
  {
    msg_.crc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_reserve
{
public:
  explicit Init_HighState_reserve(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_crc reserve(::unitree_legged_msgs::msg::HighState::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return Init_HighState_crc(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_wireless_remote
{
public:
  explicit Init_HighState_wireless_remote(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_reserve wireless_remote(::unitree_legged_msgs::msg::HighState::_wireless_remote_type arg)
  {
    msg_.wireless_remote = std::move(arg);
    return Init_HighState_reserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_foot_speed2_body
{
public:
  explicit Init_HighState_foot_speed2_body(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_wireless_remote foot_speed2_body(::unitree_legged_msgs::msg::HighState::_foot_speed2_body_type arg)
  {
    msg_.foot_speed2_body = std::move(arg);
    return Init_HighState_wireless_remote(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_foot_position2_body
{
public:
  explicit Init_HighState_foot_position2_body(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_foot_speed2_body foot_position2_body(::unitree_legged_msgs::msg::HighState::_foot_position2_body_type arg)
  {
    msg_.foot_position2_body = std::move(arg);
    return Init_HighState_foot_speed2_body(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_range_obstacle
{
public:
  explicit Init_HighState_range_obstacle(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_foot_position2_body range_obstacle(::unitree_legged_msgs::msg::HighState::_range_obstacle_type arg)
  {
    msg_.range_obstacle = std::move(arg);
    return Init_HighState_foot_position2_body(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_yaw_speed
{
public:
  explicit Init_HighState_yaw_speed(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_range_obstacle yaw_speed(::unitree_legged_msgs::msg::HighState::_yaw_speed_type arg)
  {
    msg_.yaw_speed = std::move(arg);
    return Init_HighState_range_obstacle(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_velocity
{
public:
  explicit Init_HighState_velocity(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_yaw_speed velocity(::unitree_legged_msgs::msg::HighState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_HighState_yaw_speed(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_body_height
{
public:
  explicit Init_HighState_body_height(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_velocity body_height(::unitree_legged_msgs::msg::HighState::_body_height_type arg)
  {
    msg_.body_height = std::move(arg);
    return Init_HighState_velocity(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_position
{
public:
  explicit Init_HighState_position(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_body_height position(::unitree_legged_msgs::msg::HighState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_HighState_body_height(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_foot_raise_height
{
public:
  explicit Init_HighState_foot_raise_height(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_position foot_raise_height(::unitree_legged_msgs::msg::HighState::_foot_raise_height_type arg)
  {
    msg_.foot_raise_height = std::move(arg);
    return Init_HighState_position(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_gait_type
{
public:
  explicit Init_HighState_gait_type(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_foot_raise_height gait_type(::unitree_legged_msgs::msg::HighState::_gait_type_type arg)
  {
    msg_.gait_type = std::move(arg);
    return Init_HighState_foot_raise_height(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_progress
{
public:
  explicit Init_HighState_progress(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_gait_type progress(::unitree_legged_msgs::msg::HighState::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return Init_HighState_gait_type(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_mode
{
public:
  explicit Init_HighState_mode(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_progress mode(::unitree_legged_msgs::msg::HighState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_HighState_progress(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_foot_force_est
{
public:
  explicit Init_HighState_foot_force_est(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_mode foot_force_est(::unitree_legged_msgs::msg::HighState::_foot_force_est_type arg)
  {
    msg_.foot_force_est = std::move(arg);
    return Init_HighState_mode(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_foot_force
{
public:
  explicit Init_HighState_foot_force(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_foot_force_est foot_force(::unitree_legged_msgs::msg::HighState::_foot_force_type arg)
  {
    msg_.foot_force = std::move(arg);
    return Init_HighState_foot_force_est(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_bms
{
public:
  explicit Init_HighState_bms(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_foot_force bms(::unitree_legged_msgs::msg::HighState::_bms_type arg)
  {
    msg_.bms = std::move(arg);
    return Init_HighState_foot_force(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_motor_state
{
public:
  explicit Init_HighState_motor_state(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_bms motor_state(::unitree_legged_msgs::msg::HighState::_motor_state_type arg)
  {
    msg_.motor_state = std::move(arg);
    return Init_HighState_bms(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_imu
{
public:
  explicit Init_HighState_imu(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_motor_state imu(::unitree_legged_msgs::msg::HighState::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_HighState_motor_state(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_bandwidth
{
public:
  explicit Init_HighState_bandwidth(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_imu bandwidth(::unitree_legged_msgs::msg::HighState::_bandwidth_type arg)
  {
    msg_.bandwidth = std::move(arg);
    return Init_HighState_imu(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_version
{
public:
  explicit Init_HighState_version(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_bandwidth version(::unitree_legged_msgs::msg::HighState::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_HighState_bandwidth(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_sn
{
public:
  explicit Init_HighState_sn(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_version sn(::unitree_legged_msgs::msg::HighState::_sn_type arg)
  {
    msg_.sn = std::move(arg);
    return Init_HighState_version(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_framereserve
{
public:
  explicit Init_HighState_framereserve(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_sn framereserve(::unitree_legged_msgs::msg::HighState::_framereserve_type arg)
  {
    msg_.framereserve = std::move(arg);
    return Init_HighState_sn(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_levelflag
{
public:
  explicit Init_HighState_levelflag(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_framereserve levelflag(::unitree_legged_msgs::msg::HighState::_levelflag_type arg)
  {
    msg_.levelflag = std::move(arg);
    return Init_HighState_framereserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_head
{
public:
  explicit Init_HighState_head(::unitree_legged_msgs::msg::HighState & msg)
  : msg_(msg)
  {}
  Init_HighState_levelflag head(::unitree_legged_msgs::msg::HighState::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_HighState_levelflag(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

class Init_HighState_stamp
{
public:
  Init_HighState_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HighState_head stamp(::unitree_legged_msgs::msg::HighState::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_HighState_head(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::HighState>()
{
  return unitree_legged_msgs::msg::builder::Init_HighState_stamp();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__BUILDER_HPP_
