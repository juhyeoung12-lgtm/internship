// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_legged_msgs:msg/IMU.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__IMU__STRUCT_H_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/IMU in the package unitree_legged_msgs.
typedef struct unitree_legged_msgs__msg__IMU
{
  float quaternion[4];
  float gyroscope[3];
  float accelerometer[3];
  float rpy[3];
  int8_t temperature;
} unitree_legged_msgs__msg__IMU;

// Struct for a sequence of unitree_legged_msgs__msg__IMU.
typedef struct unitree_legged_msgs__msg__IMU__Sequence
{
  unitree_legged_msgs__msg__IMU * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_legged_msgs__msg__IMU__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__IMU__STRUCT_H_
