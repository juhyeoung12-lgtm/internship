// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_legged_msgs:msg/HighCmd.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__STRUCT_H_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bms'
#include "unitree_legged_msgs/msg/detail/bms_cmd__struct.h"
// Member 'led'
#include "unitree_legged_msgs/msg/detail/led__struct.h"

/// Struct defined in msg/HighCmd in the package unitree_legged_msgs.
typedef struct unitree_legged_msgs__msg__HighCmd
{
  uint8_t head[2];
  uint8_t levelflag;
  uint8_t framereserve;
  uint32_t sn[2];
  uint32_t version[2];
  uint16_t bandwidth;
  uint8_t mode;
  uint8_t gait_type;
  uint8_t speed_level;
  float foot_raise_height;
  float body_height;
  float position[2];
  float euler[3];
  float velocity[2];
  float yaw_speed;
  unitree_legged_msgs__msg__BmsCmd bms;
  unitree_legged_msgs__msg__LED led[4];
  uint8_t wireless_remote[40];
  uint32_t reserve;
  uint32_t crc;
} unitree_legged_msgs__msg__HighCmd;

// Struct for a sequence of unitree_legged_msgs__msg__HighCmd.
typedef struct unitree_legged_msgs__msg__HighCmd__Sequence
{
  unitree_legged_msgs__msg__HighCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_legged_msgs__msg__HighCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_CMD__STRUCT_H_
