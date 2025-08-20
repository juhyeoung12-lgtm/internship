// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/Cartesian.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__CARTESIAN__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__CARTESIAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/cartesian__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_Cartesian_z
{
public:
  explicit Init_Cartesian_z(::unitree_legged_msgs::msg::Cartesian & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::Cartesian z(::unitree_legged_msgs::msg::Cartesian::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::Cartesian msg_;
};

class Init_Cartesian_y
{
public:
  explicit Init_Cartesian_y(::unitree_legged_msgs::msg::Cartesian & msg)
  : msg_(msg)
  {}
  Init_Cartesian_z y(::unitree_legged_msgs::msg::Cartesian::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Cartesian_z(msg_);
  }

private:
  ::unitree_legged_msgs::msg::Cartesian msg_;
};

class Init_Cartesian_x
{
public:
  Init_Cartesian_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cartesian_y x(::unitree_legged_msgs::msg::Cartesian::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Cartesian_y(msg_);
  }

private:
  ::unitree_legged_msgs::msg::Cartesian msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::Cartesian>()
{
  return unitree_legged_msgs::msg::builder::Init_Cartesian_x();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__CARTESIAN__BUILDER_HPP_
