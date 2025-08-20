// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/low_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_LowState_velocity_w
{
public:
  explicit Init_LowState_velocity_w(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::LowState velocity_w(::unitree_legged_msgs::msg::LowState::_velocity_w_type arg)
  {
    msg_.velocity_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_velocity
{
public:
  explicit Init_LowState_velocity(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_velocity_w velocity(::unitree_legged_msgs::msg::LowState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_LowState_velocity_w(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_position
{
public:
  explicit Init_LowState_position(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_velocity position(::unitree_legged_msgs::msg::LowState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_LowState_velocity(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_ee_force
{
public:
  explicit Init_LowState_ee_force(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_position ee_force(::unitree_legged_msgs::msg::LowState::_ee_force_type arg)
  {
    msg_.ee_force = std::move(arg);
    return Init_LowState_position(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_ee_force_raw
{
public:
  explicit Init_LowState_ee_force_raw(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_ee_force ee_force_raw(::unitree_legged_msgs::msg::LowState::_ee_force_raw_type arg)
  {
    msg_.ee_force_raw = std::move(arg);
    return Init_LowState_ee_force(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_crc
{
public:
  explicit Init_LowState_crc(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_ee_force_raw crc(::unitree_legged_msgs::msg::LowState::_crc_type arg)
  {
    msg_.crc = std::move(arg);
    return Init_LowState_ee_force_raw(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_reserve
{
public:
  explicit Init_LowState_reserve(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_crc reserve(::unitree_legged_msgs::msg::LowState::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return Init_LowState_crc(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_wireless_remote
{
public:
  explicit Init_LowState_wireless_remote(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_reserve wireless_remote(::unitree_legged_msgs::msg::LowState::_wireless_remote_type arg)
  {
    msg_.wireless_remote = std::move(arg);
    return Init_LowState_reserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_tick
{
public:
  explicit Init_LowState_tick(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_wireless_remote tick(::unitree_legged_msgs::msg::LowState::_tick_type arg)
  {
    msg_.tick = std::move(arg);
    return Init_LowState_wireless_remote(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_foot_force_est
{
public:
  explicit Init_LowState_foot_force_est(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_tick foot_force_est(::unitree_legged_msgs::msg::LowState::_foot_force_est_type arg)
  {
    msg_.foot_force_est = std::move(arg);
    return Init_LowState_tick(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_foot_force
{
public:
  explicit Init_LowState_foot_force(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_foot_force_est foot_force(::unitree_legged_msgs::msg::LowState::_foot_force_type arg)
  {
    msg_.foot_force = std::move(arg);
    return Init_LowState_foot_force_est(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_bms
{
public:
  explicit Init_LowState_bms(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_foot_force bms(::unitree_legged_msgs::msg::LowState::_bms_type arg)
  {
    msg_.bms = std::move(arg);
    return Init_LowState_foot_force(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_motor_state
{
public:
  explicit Init_LowState_motor_state(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_bms motor_state(::unitree_legged_msgs::msg::LowState::_motor_state_type arg)
  {
    msg_.motor_state = std::move(arg);
    return Init_LowState_bms(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_imu
{
public:
  explicit Init_LowState_imu(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_motor_state imu(::unitree_legged_msgs::msg::LowState::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_LowState_motor_state(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_bandwidth
{
public:
  explicit Init_LowState_bandwidth(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_imu bandwidth(::unitree_legged_msgs::msg::LowState::_bandwidth_type arg)
  {
    msg_.bandwidth = std::move(arg);
    return Init_LowState_imu(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_version
{
public:
  explicit Init_LowState_version(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_bandwidth version(::unitree_legged_msgs::msg::LowState::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_LowState_bandwidth(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_sn
{
public:
  explicit Init_LowState_sn(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_version sn(::unitree_legged_msgs::msg::LowState::_sn_type arg)
  {
    msg_.sn = std::move(arg);
    return Init_LowState_version(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_framereserve
{
public:
  explicit Init_LowState_framereserve(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_sn framereserve(::unitree_legged_msgs::msg::LowState::_framereserve_type arg)
  {
    msg_.framereserve = std::move(arg);
    return Init_LowState_sn(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_levelflag
{
public:
  explicit Init_LowState_levelflag(::unitree_legged_msgs::msg::LowState & msg)
  : msg_(msg)
  {}
  Init_LowState_framereserve levelflag(::unitree_legged_msgs::msg::LowState::_levelflag_type arg)
  {
    msg_.levelflag = std::move(arg);
    return Init_LowState_framereserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

class Init_LowState_head
{
public:
  Init_LowState_head()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LowState_levelflag head(::unitree_legged_msgs::msg::LowState::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_LowState_levelflag(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LowState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::LowState>()
{
  return unitree_legged_msgs::msg::builder::Init_LowState_head();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__BUILDER_HPP_
