// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_legged_msgs:msg/LED.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__TRAITS_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_legged_msgs/msg/detail/led__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_legged_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LED & msg,
  std::ostream & out)
{
  out << "{";
  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LED & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LED & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace unitree_legged_msgs

namespace rosidl_generator_traits
{

[[deprecated("use unitree_legged_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_legged_msgs::msg::LED & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_legged_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_legged_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const unitree_legged_msgs::msg::LED & msg)
{
  return unitree_legged_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_legged_msgs::msg::LED>()
{
  return "unitree_legged_msgs::msg::LED";
}

template<>
inline const char * name<unitree_legged_msgs::msg::LED>()
{
  return "unitree_legged_msgs/msg/LED";
}

template<>
struct has_fixed_size<unitree_legged_msgs::msg::LED>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_legged_msgs::msg::LED>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_legged_msgs::msg::LED>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__LED__TRAITS_HPP_
