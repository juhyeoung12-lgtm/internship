// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/BmsCmd.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__BMS_CMD__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__BMS_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/bms_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_BmsCmd_reserve
{
public:
  explicit Init_BmsCmd_reserve(::unitree_legged_msgs::msg::BmsCmd & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::BmsCmd reserve(::unitree_legged_msgs::msg::BmsCmd::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::BmsCmd msg_;
};

class Init_BmsCmd_off
{
public:
  Init_BmsCmd_off()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BmsCmd_reserve off(::unitree_legged_msgs::msg::BmsCmd::_off_type arg)
  {
    msg_.off = std::move(arg);
    return Init_BmsCmd_reserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::BmsCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::BmsCmd>()
{
  return unitree_legged_msgs::msg::builder::Init_BmsCmd_off();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__BMS_CMD__BUILDER_HPP_
