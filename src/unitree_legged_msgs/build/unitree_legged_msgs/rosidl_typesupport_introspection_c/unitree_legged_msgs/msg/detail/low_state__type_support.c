// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from unitree_legged_msgs:msg/LowState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "unitree_legged_msgs/msg/detail/low_state__rosidl_typesupport_introspection_c.h"
#include "unitree_legged_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "unitree_legged_msgs/msg/detail/low_state__functions.h"
#include "unitree_legged_msgs/msg/detail/low_state__struct.h"


// Include directives for member types
// Member `imu`
#include "unitree_legged_msgs/msg/imu.h"
// Member `imu`
#include "unitree_legged_msgs/msg/detail/imu__rosidl_typesupport_introspection_c.h"
// Member `motor_state`
#include "unitree_legged_msgs/msg/motor_state.h"
// Member `motor_state`
#include "unitree_legged_msgs/msg/detail/motor_state__rosidl_typesupport_introspection_c.h"
// Member `bms`
#include "unitree_legged_msgs/msg/bms_state.h"
// Member `bms`
#include "unitree_legged_msgs/msg/detail/bms_state__rosidl_typesupport_introspection_c.h"
// Member `ee_force_raw`
// Member `ee_force`
// Member `position`
// Member `velocity`
// Member `velocity_w`
#include "unitree_legged_msgs/msg/cartesian.h"
// Member `ee_force_raw`
// Member `ee_force`
// Member `position`
// Member `velocity`
// Member `velocity_w`
#include "unitree_legged_msgs/msg/detail/cartesian__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  unitree_legged_msgs__msg__LowState__init(message_memory);
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_fini_function(void * message_memory)
{
  unitree_legged_msgs__msg__LowState__fini(message_memory);
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__head(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__head(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__head(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__head(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__head(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__head(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__head(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__sn(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__sn(
  const void * untyped_member, size_t index)
{
  const uint32_t * member =
    (const uint32_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__sn(
  void * untyped_member, size_t index)
{
  uint32_t * member =
    (uint32_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__sn(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__sn(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__sn(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__sn(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__version(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__version(
  const void * untyped_member, size_t index)
{
  const uint32_t * member =
    (const uint32_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__version(
  void * untyped_member, size_t index)
{
  uint32_t * member =
    (uint32_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__version(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__version(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__motor_state(
  const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__motor_state(
  const void * untyped_member, size_t index)
{
  const unitree_legged_msgs__msg__MotorState * member =
    (const unitree_legged_msgs__msg__MotorState *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__motor_state(
  void * untyped_member, size_t index)
{
  unitree_legged_msgs__msg__MotorState * member =
    (unitree_legged_msgs__msg__MotorState *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__motor_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const unitree_legged_msgs__msg__MotorState * item =
    ((const unitree_legged_msgs__msg__MotorState *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__motor_state(untyped_member, index));
  unitree_legged_msgs__msg__MotorState * value =
    (unitree_legged_msgs__msg__MotorState *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__motor_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  unitree_legged_msgs__msg__MotorState * item =
    ((unitree_legged_msgs__msg__MotorState *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__motor_state(untyped_member, index));
  const unitree_legged_msgs__msg__MotorState * value =
    (const unitree_legged_msgs__msg__MotorState *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__foot_force(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force(
  const void * untyped_member, size_t index)
{
  const int16_t * member =
    (const int16_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force(
  void * untyped_member, size_t index)
{
  int16_t * member =
    (int16_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__foot_force(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__foot_force(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__foot_force_est(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force_est(
  const void * untyped_member, size_t index)
{
  const int16_t * member =
    (const int16_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force_est(
  void * untyped_member, size_t index)
{
  int16_t * member =
    (int16_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__foot_force_est(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force_est(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__foot_force_est(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force_est(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__wireless_remote(
  const void * untyped_member)
{
  (void)untyped_member;
  return 40;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__wireless_remote(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__wireless_remote(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__wireless_remote(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__wireless_remote(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__wireless_remote(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__wireless_remote(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__ee_force_raw(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force_raw(
  const void * untyped_member, size_t index)
{
  const unitree_legged_msgs__msg__Cartesian * member =
    (const unitree_legged_msgs__msg__Cartesian *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force_raw(
  void * untyped_member, size_t index)
{
  unitree_legged_msgs__msg__Cartesian * member =
    (unitree_legged_msgs__msg__Cartesian *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__ee_force_raw(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const unitree_legged_msgs__msg__Cartesian * item =
    ((const unitree_legged_msgs__msg__Cartesian *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force_raw(untyped_member, index));
  unitree_legged_msgs__msg__Cartesian * value =
    (unitree_legged_msgs__msg__Cartesian *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__ee_force_raw(
  void * untyped_member, size_t index, const void * untyped_value)
{
  unitree_legged_msgs__msg__Cartesian * item =
    ((unitree_legged_msgs__msg__Cartesian *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force_raw(untyped_member, index));
  const unitree_legged_msgs__msg__Cartesian * value =
    (const unitree_legged_msgs__msg__Cartesian *)(untyped_value);
  *item = *value;
}

size_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__ee_force(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force(
  const void * untyped_member, size_t index)
{
  const unitree_legged_msgs__msg__Cartesian * member =
    (const unitree_legged_msgs__msg__Cartesian *)(untyped_member);
  return &member[index];
}

void * unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force(
  void * untyped_member, size_t index)
{
  unitree_legged_msgs__msg__Cartesian * member =
    (unitree_legged_msgs__msg__Cartesian *)(untyped_member);
  return &member[index];
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__ee_force(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const unitree_legged_msgs__msg__Cartesian * item =
    ((const unitree_legged_msgs__msg__Cartesian *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force(untyped_member, index));
  unitree_legged_msgs__msg__Cartesian * value =
    (unitree_legged_msgs__msg__Cartesian *)(untyped_value);
  *value = *item;
}

void unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__ee_force(
  void * untyped_member, size_t index, const void * untyped_value)
{
  unitree_legged_msgs__msg__Cartesian * item =
    ((unitree_legged_msgs__msg__Cartesian *)
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force(untyped_member, index));
  const unitree_legged_msgs__msg__Cartesian * value =
    (const unitree_legged_msgs__msg__Cartesian *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[20] = {
  {
    "head",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, head),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__head,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__head,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__head,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__head,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__head,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "levelflag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, levelflag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "framereserve",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, framereserve),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sn",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, sn),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__sn,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__sn,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__sn,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__sn,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__sn,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, version),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__version,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__version,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__version,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__version,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__version,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bandwidth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, bandwidth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, imu),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, motor_state),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__motor_state,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__motor_state,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__motor_state,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__motor_state,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__motor_state,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, bms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "foot_force",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, foot_force),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__foot_force,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__foot_force,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__foot_force,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "foot_force_est",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, foot_force_est),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__foot_force_est,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__foot_force_est,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__foot_force_est,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__foot_force_est,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__foot_force_est,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tick",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, tick),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wireless_remote",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    40,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, wireless_remote),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__wireless_remote,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__wireless_remote,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__wireless_remote,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__wireless_remote,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__wireless_remote,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserve",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, reserve),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "crc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, crc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ee_force_raw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, ee_force_raw),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__ee_force_raw,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force_raw,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force_raw,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__ee_force_raw,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__ee_force_raw,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ee_force",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, ee_force),  // bytes offset in struct
    NULL,  // default value
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__size_function__LowState__ee_force,  // size() function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_const_function__LowState__ee_force,  // get_const(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__get_function__LowState__ee_force,  // get(index) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__fetch_function__LowState__ee_force,  // fetch(index, &value) function pointer
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__assign_function__LowState__ee_force,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity_w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_legged_msgs__msg__LowState, velocity_w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_members = {
  "unitree_legged_msgs__msg",  // message namespace
  "LowState",  // message name
  20,  // number of fields
  sizeof(unitree_legged_msgs__msg__LowState),
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array,  // message members
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_init_function,  // function to initialize message memory (memory has to be allocated)
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_type_support_handle = {
  0,
  &unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unitree_legged_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, LowState)() {
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, IMU)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, MotorState)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, BmsState)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[15].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, Cartesian)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[16].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, Cartesian)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[17].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, Cartesian)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[18].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, Cartesian)();
  unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_member_array[19].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_legged_msgs, msg, Cartesian)();
  if (!unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_type_support_handle.typesupport_identifier) {
    unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &unitree_legged_msgs__msg__LowState__rosidl_typesupport_introspection_c__LowState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
