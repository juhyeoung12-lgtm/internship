// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_legged_msgs:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__STRUCT_H_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imu'
#include "unitree_legged_msgs/msg/detail/imu__struct.h"
// Member 'motor_state'
#include "unitree_legged_msgs/msg/detail/motor_state__struct.h"
// Member 'bms'
#include "unitree_legged_msgs/msg/detail/bms_state__struct.h"
// Member 'ee_force_raw'
// Member 'ee_force'
// Member 'position'
// Member 'velocity'
// Member 'velocity_w'
#include "unitree_legged_msgs/msg/detail/cartesian__struct.h"

/// Struct defined in msg/LowState in the package unitree_legged_msgs.
typedef struct unitree_legged_msgs__msg__LowState
{
  uint8_t head[2];
  uint8_t levelflag;
  uint8_t framereserve;
  uint32_t sn[2];
  uint32_t version[2];
  uint16_t bandwidth;
  unitree_legged_msgs__msg__IMU imu;
  unitree_legged_msgs__msg__MotorState motor_state[20];
  unitree_legged_msgs__msg__BmsState bms;
  int16_t foot_force[4];
  int16_t foot_force_est[4];
  uint32_t tick;
  uint8_t wireless_remote[40];
  uint32_t reserve;
  uint32_t crc;
  /// Old version Aliengo does not have:
  unitree_legged_msgs__msg__Cartesian ee_force_raw[4];
  /// it's a 1-DOF force infact, but we use 3-DOF here just for visualization
  unitree_legged_msgs__msg__Cartesian ee_force[4];
  /// will delete
  unitree_legged_msgs__msg__Cartesian position;
  /// will delete
  unitree_legged_msgs__msg__Cartesian velocity;
  /// will delete
  unitree_legged_msgs__msg__Cartesian velocity_w;
} unitree_legged_msgs__msg__LowState;

// Struct for a sequence of unitree_legged_msgs__msg__LowState.
typedef struct unitree_legged_msgs__msg__LowState__Sequence
{
  unitree_legged_msgs__msg__LowState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_legged_msgs__msg__LowState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_STATE__STRUCT_H_
