// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/LED.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/led__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_LED_b
{
public:
  explicit Init_LED_b(::unitree_legged_msgs::msg::LED & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::LED b(::unitree_legged_msgs::msg::LED::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LED msg_;
};

class Init_LED_g
{
public:
  explicit Init_LED_g(::unitree_legged_msgs::msg::LED & msg)
  : msg_(msg)
  {}
  Init_LED_b g(::unitree_legged_msgs::msg::LED::_g_type arg)
  {
    msg_.g = std::move(arg);
    return Init_LED_b(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LED msg_;
};

class Init_LED_r
{
public:
  Init_LED_r()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LED_g r(::unitree_legged_msgs::msg::LED::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_LED_g(msg_);
  }

private:
  ::unitree_legged_msgs::msg::LED msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::LED>()
{
  return unitree_legged_msgs::msg::builder::Init_LED_r();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__BUILDER_HPP_
