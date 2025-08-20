// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_legged_msgs:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_CMD__STRUCT_H_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_cmd'
#include "unitree_legged_msgs/msg/detail/motor_cmd__struct.h"
// Member 'bms'
#include "unitree_legged_msgs/msg/detail/bms_cmd__struct.h"

/// Struct defined in msg/LowCmd in the package unitree_legged_msgs.
typedef struct unitree_legged_msgs__msg__LowCmd
{
  uint8_t head[2];
  uint8_t levelflag;
  uint8_t framereserve;
  uint32_t sn[2];
  uint32_t version[2];
  uint16_t bandwidth;
  unitree_legged_msgs__msg__MotorCmd motor_cmd[20];
  unitree_legged_msgs__msg__BmsCmd bms;
  uint8_t wireless_remote[40];
  uint32_t reserve;
  uint32_t crc;
} unitree_legged_msgs__msg__LowCmd;

// Struct for a sequence of unitree_legged_msgs__msg__LowCmd.
typedef struct unitree_legged_msgs__msg__LowCmd__Sequence
{
  unitree_legged_msgs__msg__LowCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_legged_msgs__msg__LowCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__LOW_CMD__STRUCT_H_
