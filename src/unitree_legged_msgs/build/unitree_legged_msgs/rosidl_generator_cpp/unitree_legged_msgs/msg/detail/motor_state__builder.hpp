// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_legged_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_legged_msgs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_legged_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorState_reserve
{
public:
  explicit Init_MotorState_reserve(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::unitree_legged_msgs::msg::MotorState reserve(::unitree_legged_msgs::msg::MotorState::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_temperature
{
public:
  explicit Init_MotorState_temperature(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_reserve temperature(::unitree_legged_msgs::msg::MotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_MotorState_reserve(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_ddq_raw
{
public:
  explicit Init_MotorState_ddq_raw(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_temperature ddq_raw(::unitree_legged_msgs::msg::MotorState::_ddq_raw_type arg)
  {
    msg_.ddq_raw = std::move(arg);
    return Init_MotorState_temperature(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_dq_raw
{
public:
  explicit Init_MotorState_dq_raw(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq_raw dq_raw(::unitree_legged_msgs::msg::MotorState::_dq_raw_type arg)
  {
    msg_.dq_raw = std::move(arg);
    return Init_MotorState_ddq_raw(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_q_raw
{
public:
  explicit Init_MotorState_q_raw(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_dq_raw q_raw(::unitree_legged_msgs::msg::MotorState::_q_raw_type arg)
  {
    msg_.q_raw = std::move(arg);
    return Init_MotorState_dq_raw(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_tauest
{
public:
  explicit Init_MotorState_tauest(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_q_raw tauest(::unitree_legged_msgs::msg::MotorState::_tauest_type arg)
  {
    msg_.tauest = std::move(arg);
    return Init_MotorState_q_raw(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_ddq
{
public:
  explicit Init_MotorState_ddq(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_tauest ddq(::unitree_legged_msgs::msg::MotorState::_ddq_type arg)
  {
    msg_.ddq = std::move(arg);
    return Init_MotorState_tauest(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_dq
{
public:
  explicit Init_MotorState_dq(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq dq(::unitree_legged_msgs::msg::MotorState::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return Init_MotorState_ddq(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_q
{
public:
  explicit Init_MotorState_q(::unitree_legged_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_dq q(::unitree_legged_msgs::msg::MotorState::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_MotorState_dq(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

class Init_MotorState_mode
{
public:
  Init_MotorState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_q mode(::unitree_legged_msgs::msg::MotorState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MotorState_q(msg_);
  }

private:
  ::unitree_legged_msgs::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_legged_msgs::msg::MotorState>()
{
  return unitree_legged_msgs::msg::builder::Init_MotorState_mode();
}

}  // namespace unitree_legged_msgs

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
