// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/HighCmd.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/high_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_HighCmd_crc
{
public:
  explicit Init_HighCmd_crc(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::HighCmd crc(::unitree_legged_msgs::msg::HighCmd::_crc_type arg)
  {
    msg_.crc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_reserve
{
public:
  explicit Init_HighCmd_reserve(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_crc reserve(::unitree_legged_msgs::msg::HighCmd::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return Init_HighCmd_crc(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_wireless_remote
{
public:
  explicit Init_HighCmd_wireless_remote(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_reserve wireless_remote(::unitree_legged_msgs::msg::HighCmd::_wireless_remote_type arg)
  {
    msg_.wireless_remote = std::move(arg);
    return Init_HighCmd_reserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_led
{
public:
  explicit Init_HighCmd_led(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_wireless_remote led(::unitree_legged_msgs::msg::HighCmd::_led_type arg)
  {
    msg_.led = std::move(arg);
    return Init_HighCmd_wireless_remote(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_bms
{
public:
  explicit Init_HighCmd_bms(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_led bms(::unitree_legged_msgs::msg::HighCmd::_bms_type arg)
  {
    msg_.bms = std::move(arg);
    return Init_HighCmd_led(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_yaw_speed
{
public:
  explicit Init_HighCmd_yaw_speed(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_bms yaw_speed(::unitree_legged_msgs::msg::HighCmd::_yaw_speed_type arg)
  {
    msg_.yaw_speed = std::move(arg);
    return Init_HighCmd_bms(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_velocity
{
public:
  explicit Init_HighCmd_velocity(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_yaw_speed velocity(::unitree_legged_msgs::msg::HighCmd::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_HighCmd_yaw_speed(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_euler
{
public:
  explicit Init_HighCmd_euler(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_velocity euler(::unitree_legged_msgs::msg::HighCmd::_euler_type arg)
  {
    msg_.euler = std::move(arg);
    return Init_HighCmd_velocity(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_position
{
public:
  explicit Init_HighCmd_position(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_euler position(::unitree_legged_msgs::msg::HighCmd::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_HighCmd_euler(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_body_height
{
public:
  explicit Init_HighCmd_body_height(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_position body_height(::unitree_legged_msgs::msg::HighCmd::_body_height_type arg)
  {
    msg_.body_height = std::move(arg);
    return Init_HighCmd_position(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_foot_raise_height
{
public:
  explicit Init_HighCmd_foot_raise_height(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_body_height foot_raise_height(::unitree_legged_msgs::msg::HighCmd::_foot_raise_height_type arg)
  {
    msg_.foot_raise_height = std::move(arg);
    return Init_HighCmd_body_height(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_speed_level
{
public:
  explicit Init_HighCmd_speed_level(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_foot_raise_height speed_level(::unitree_legged_msgs::msg::HighCmd::_speed_level_type arg)
  {
    msg_.speed_level = std::move(arg);
    return Init_HighCmd_foot_raise_height(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_gait_type
{
public:
  explicit Init_HighCmd_gait_type(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_speed_level gait_type(::unitree_legged_msgs::msg::HighCmd::_gait_type_type arg)
  {
    msg_.gait_type = std::move(arg);
    return Init_HighCmd_speed_level(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_mode
{
public:
  explicit Init_HighCmd_mode(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_gait_type mode(::unitree_legged_msgs::msg::HighCmd::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_HighCmd_gait_type(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_bandwidth
{
public:
  explicit Init_HighCmd_bandwidth(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_mode bandwidth(::unitree_legged_msgs::msg::HighCmd::_bandwidth_type arg)
  {
    msg_.bandwidth = std::move(arg);
    return Init_HighCmd_mode(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_version
{
public:
  explicit Init_HighCmd_version(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_bandwidth version(::unitree_legged_msgs::msg::HighCmd::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_HighCmd_bandwidth(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_sn
{
public:
  explicit Init_HighCmd_sn(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_version sn(::unitree_legged_msgs::msg::HighCmd::_sn_type arg)
  {
    msg_.sn = std::move(arg);
    return Init_HighCmd_version(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_framereserve
{
public:
  explicit Init_HighCmd_framereserve(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_sn framereserve(::unitree_legged_msgs::msg::HighCmd::_framereserve_type arg)
  {
    msg_.framereserve = std::move(arg);
    return Init_HighCmd_sn(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_levelflag
{
public:
  explicit Init_HighCmd_levelflag(::unitree_legged_msgs::msg::HighCmd & msg)
  : msg_(msg)
  {}
  Init_HighCmd_framereserve levelflag(::unitree_legged_msgs::msg::HighCmd::_levelflag_type arg)
  {
    msg_.levelflag = std::move(arg);
    return Init_HighCmd_framereserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

class Init_HighCmd_head
{
public:
  Init_HighCmd_head()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HighCmd_levelflag head(::unitree_legged_msgs::msg::HighCmd::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_HighCmd_levelflag(msg_);
  }

private:
  ::unitree_legged_msgs::msg::HighCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::HighCmd>()
{
  return unitree_legged_msgs::msg::builder::Init_HighCmd_head();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__BUILDER_HPP_
