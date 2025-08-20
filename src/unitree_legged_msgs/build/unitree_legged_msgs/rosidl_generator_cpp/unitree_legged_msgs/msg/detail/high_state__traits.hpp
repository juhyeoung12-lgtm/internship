// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_legged_msgs:msg/HighState.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__TRAITS_HPP_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_legged_msgs/msg/detail/high_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'imu'
#include "unitree_legged_msgs/msg/detail/imu__traits.hpp"
// Member 'motor_state'
#include "unitree_legged_msgs/msg/detail/motor_state__traits.hpp"
// Member 'bms'
#include "unitree_legged_msgs/msg/detail/bms_state__traits.hpp"
// Member 'foot_position2_body'
// Member 'foot_speed2_body'
#include "unitree_legged_msgs/msg/detail/cartesian__traits.hpp"

namespace unitree_legged_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HighState & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: head
  {
    if (msg.head.size() == 0) {
      out << "head: []";
    } else {
      out << "head: [";
      size_t pending_items = msg.head.size();
      for (auto item : msg.head) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: levelflag
  {
    out << "levelflag: ";
    rosidl_generator_traits::value_to_yaml(msg.levelflag, out);
    out << ", ";
  }

  // member: framereserve
  {
    out << "framereserve: ";
    rosidl_generator_traits::value_to_yaml(msg.framereserve, out);
    out << ", ";
  }

  // member: sn
  {
    if (msg.sn.size() == 0) {
      out << "sn: []";
    } else {
      out << "sn: [";
      size_t pending_items = msg.sn.size();
      for (auto item : msg.sn) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: version
  {
    if (msg.version.size() == 0) {
      out << "version: []";
    } else {
      out << "version: [";
      size_t pending_items = msg.version.size();
      for (auto item : msg.version) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bandwidth
  {
    out << "bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.bandwidth, out);
    out << ", ";
  }

  // member: imu
  {
    out << "imu: ";
    to_flow_style_yaml(msg.imu, out);
    out << ", ";
  }

  // member: motor_state
  {
    if (msg.motor_state.size() == 0) {
      out << "motor_state: []";
    } else {
      out << "motor_state: [";
      size_t pending_items = msg.motor_state.size();
      for (auto item : msg.motor_state) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bms
  {
    out << "bms: ";
    to_flow_style_yaml(msg.bms, out);
    out << ", ";
  }

  // member: foot_force
  {
    if (msg.foot_force.size() == 0) {
      out << "foot_force: []";
    } else {
      out << "foot_force: [";
      size_t pending_items = msg.foot_force.size();
      for (auto item : msg.foot_force) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: foot_force_est
  {
    if (msg.foot_force_est.size() == 0) {
      out << "foot_force_est: []";
    } else {
      out << "foot_force_est: [";
      size_t pending_items = msg.foot_force_est.size();
      for (auto item : msg.foot_force_est) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << ", ";
  }

  // member: gait_type
  {
    out << "gait_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gait_type, out);
    out << ", ";
  }

  // member: foot_raise_height
  {
    out << "foot_raise_height: ";
    rosidl_generator_traits::value_to_yaml(msg.foot_raise_height, out);
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: body_height
  {
    out << "body_height: ";
    rosidl_generator_traits::value_to_yaml(msg.body_height, out);
    out << ", ";
  }

  // member: velocity
  {
    if (msg.velocity.size() == 0) {
      out << "velocity: []";
    } else {
      out << "velocity: [";
      size_t pending_items = msg.velocity.size();
      for (auto item : msg.velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: yaw_speed
  {
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << ", ";
  }

  // member: range_obstacle
  {
    if (msg.range_obstacle.size() == 0) {
      out << "range_obstacle: []";
    } else {
      out << "range_obstacle: [";
      size_t pending_items = msg.range_obstacle.size();
      for (auto item : msg.range_obstacle) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: foot_position2_body
  {
    if (msg.foot_position2_body.size() == 0) {
      out << "foot_position2_body: []";
    } else {
      out << "foot_position2_body: [";
      size_t pending_items = msg.foot_position2_body.size();
      for (auto item : msg.foot_position2_body) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: foot_speed2_body
  {
    if (msg.foot_speed2_body.size() == 0) {
      out << "foot_speed2_body: []";
    } else {
      out << "foot_speed2_body: [";
      size_t pending_items = msg.foot_speed2_body.size();
      for (auto item : msg.foot_speed2_body) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: wireless_remote
  {
    if (msg.wireless_remote.size() == 0) {
      out << "wireless_remote: []";
    } else {
      out << "wireless_remote: [";
      size_t pending_items = msg.wireless_remote.size();
      for (auto item : msg.wireless_remote) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: reserve
  {
    out << "reserve: ";
    rosidl_generator_traits::value_to_yaml(msg.reserve, out);
    out << ", ";
  }

  // member: crc
  {
    out << "crc: ";
    rosidl_generator_traits::value_to_yaml(msg.crc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HighState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: head
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.head.size() == 0) {
      out << "head: []\n";
    } else {
      out << "head:\n";
      for (auto item : msg.head) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: levelflag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "levelflag: ";
    rosidl_generator_traits::value_to_yaml(msg.levelflag, out);
    out << "\n";
  }

  // member: framereserve
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "framereserve: ";
    rosidl_generator_traits::value_to_yaml(msg.framereserve, out);
    out << "\n";
  }

  // member: sn
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sn.size() == 0) {
      out << "sn: []\n";
    } else {
      out << "sn:\n";
      for (auto item : msg.sn) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.version.size() == 0) {
      out << "version: []\n";
    } else {
      out << "version:\n";
      for (auto item : msg.version) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bandwidth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.bandwidth, out);
    out << "\n";
  }

  // member: imu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu:\n";
    to_block_style_yaml(msg.imu, out, indentation + 2);
  }

  // member: motor_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_state.size() == 0) {
      out << "motor_state: []\n";
    } else {
      out << "motor_state:\n";
      for (auto item : msg.motor_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: bms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bms:\n";
    to_block_style_yaml(msg.bms, out, indentation + 2);
  }

  // member: foot_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_force.size() == 0) {
      out << "foot_force: []\n";
    } else {
      out << "foot_force:\n";
      for (auto item : msg.foot_force) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: foot_force_est
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_force_est.size() == 0) {
      out << "foot_force_est: []\n";
    } else {
      out << "foot_force_est:\n";
      for (auto item : msg.foot_force_est) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }

  // member: gait_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gait_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gait_type, out);
    out << "\n";
  }

  // member: foot_raise_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "foot_raise_height: ";
    rosidl_generator_traits::value_to_yaml(msg.foot_raise_height, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: body_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_height: ";
    rosidl_generator_traits::value_to_yaml(msg.body_height, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity.size() == 0) {
      out << "velocity: []\n";
    } else {
      out << "velocity:\n";
      for (auto item : msg.velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: yaw_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << "\n";
  }

  // member: range_obstacle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.range_obstacle.size() == 0) {
      out << "range_obstacle: []\n";
    } else {
      out << "range_obstacle:\n";
      for (auto item : msg.range_obstacle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: foot_position2_body
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_position2_body.size() == 0) {
      out << "foot_position2_body: []\n";
    } else {
      out << "foot_position2_body:\n";
      for (auto item : msg.foot_position2_body) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: foot_speed2_body
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_speed2_body.size() == 0) {
      out << "foot_speed2_body: []\n";
    } else {
      out << "foot_speed2_body:\n";
      for (auto item : msg.foot_speed2_body) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: wireless_remote
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wireless_remote.size() == 0) {
      out << "wireless_remote: []\n";
    } else {
      out << "wireless_remote:\n";
      for (auto item : msg.wireless_remote) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: reserve
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reserve: ";
    rosidl_generator_traits::value_to_yaml(msg.reserve, out);
    out << "\n";
  }

  // member: crc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "crc: ";
    rosidl_generator_traits::value_to_yaml(msg.crc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HighState & msg, bool use_flow_style = false)
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
  const unitree_legged_msgs::msg::HighState & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_legged_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_legged_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const unitree_legged_msgs::msg::HighState & msg)
{
  return unitree_legged_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_legged_msgs::msg::HighState>()
{
  return "unitree_legged_msgs::msg::HighState";
}

template<>
inline const char * name<unitree_legged_msgs::msg::HighState>()
{
  return "unitree_legged_msgs/msg/HighState";
}

template<>
struct has_fixed_size<unitree_legged_msgs::msg::HighState>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<unitree_legged_msgs::msg::BmsState>::value && has_fixed_size<unitree_legged_msgs::msg::Cartesian>::value && has_fixed_size<unitree_legged_msgs::msg::IMU>::value && has_fixed_size<unitree_legged_msgs::msg::MotorState>::value> {};

template<>
struct has_bounded_size<unitree_legged_msgs::msg::HighState>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<unitree_legged_msgs::msg::BmsState>::value && has_bounded_size<unitree_legged_msgs::msg::Cartesian>::value && has_bounded_size<unitree_legged_msgs::msg::IMU>::value && has_bounded_size<unitree_legged_msgs::msg::MotorState>::value> {};

template<>
struct is_message<unitree_legged_msgs::msg::HighState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__TRAITS_HPP_
