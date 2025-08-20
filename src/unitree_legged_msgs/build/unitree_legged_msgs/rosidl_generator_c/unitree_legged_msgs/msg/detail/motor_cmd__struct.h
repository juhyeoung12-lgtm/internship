// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_legged_msgs:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
#define UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorCmd in the package unitree_legged_msgs.
typedef struct unitree_legged_msgs__msg__MotorCmd
{
  /// motor target mode
  uint8_t mode;
  /// motor target position
  float q;
  /// motor target velocity
  float dq;
  /// motor target torque
  float tau;
  /// motor spring stiffness coefficient
  float kp;
  /// motor damper coefficient
  float kd;
  /// motor target torque
  uint32_t reserve[3];
} unitree_legged_msgs__msg__MotorCmd;

// Struct for a sequence of unitree_legged_msgs__msg__MotorCmd.
typedef struct unitree_legged_msgs__msg__MotorCmd__Sequence
{
  unitree_legged_msgs__msg__MotorCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_legged_msgs__msg__MotorCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_H_
