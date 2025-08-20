// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_legged_msgs:msg/LowState.idl
// generated code does not contain a copyright notice
#include "unitree_legged_msgs/msg/detail/low_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `imu`
#include "unitree_legged_msgs/msg/detail/imu__functions.h"
// Member `motor_state`
#include "unitree_legged_msgs/msg/detail/motor_state__functions.h"
// Member `bms`
#include "unitree_legged_msgs/msg/detail/bms_state__functions.h"
// Member `ee_force_raw`
// Member `ee_force`
// Member `position`
// Member `velocity`
// Member `velocity_w`
#include "unitree_legged_msgs/msg/detail/cartesian__functions.h"

bool
unitree_legged_msgs__msg__LowState__init(unitree_legged_msgs__msg__LowState * msg)
{
  if (!msg) {
    return false;
  }
  // head
  // levelflag
  // framereserve
  // sn
  // version
  // bandwidth
  // imu
  if (!unitree_legged_msgs__msg__IMU__init(&msg->imu)) {
    unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorState__init(&msg->motor_state[i])) {
      unitree_legged_msgs__msg__LowState__fini(msg);
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsState__init(&msg->bms)) {
    unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // foot_force
  // foot_force_est
  // tick
  // wireless_remote
  // reserve
  // crc
  // ee_force_raw
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__init(&msg->ee_force_raw[i])) {
      unitree_legged_msgs__msg__LowState__fini(msg);
      return false;
    }
  }
  // ee_force
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__init(&msg->ee_force[i])) {
      unitree_legged_msgs__msg__LowState__fini(msg);
      return false;
    }
  }
  // position
  if (!unitree_legged_msgs__msg__Cartesian__init(&msg->position)) {
    unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // velocity
  if (!unitree_legged_msgs__msg__Cartesian__init(&msg->velocity)) {
    unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // velocity_w
  if (!unitree_legged_msgs__msg__Cartesian__init(&msg->velocity_w)) {
    unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  return true;
}

void
unitree_legged_msgs__msg__LowState__fini(unitree_legged_msgs__msg__LowState * msg)
{
  if (!msg) {
    return;
  }
  // head
  // levelflag
  // framereserve
  // sn
  // version
  // bandwidth
  // imu
  unitree_legged_msgs__msg__IMU__fini(&msg->imu);
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    unitree_legged_msgs__msg__MotorState__fini(&msg->motor_state[i]);
  }
  // bms
  unitree_legged_msgs__msg__BmsState__fini(&msg->bms);
  // foot_force
  // foot_force_est
  // tick
  // wireless_remote
  // reserve
  // crc
  // ee_force_raw
  for (size_t i = 0; i < 4; ++i) {
    unitree_legged_msgs__msg__Cartesian__fini(&msg->ee_force_raw[i]);
  }
  // ee_force
  for (size_t i = 0; i < 4; ++i) {
    unitree_legged_msgs__msg__Cartesian__fini(&msg->ee_force[i]);
  }
  // position
  unitree_legged_msgs__msg__Cartesian__fini(&msg->position);
  // velocity
  unitree_legged_msgs__msg__Cartesian__fini(&msg->velocity);
  // velocity_w
  unitree_legged_msgs__msg__Cartesian__fini(&msg->velocity_w);
}

bool
unitree_legged_msgs__msg__LowState__are_equal(const unitree_legged_msgs__msg__LowState * lhs, const unitree_legged_msgs__msg__LowState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // head
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->head[i] != rhs->head[i]) {
      return false;
    }
  }
  // levelflag
  if (lhs->levelflag != rhs->levelflag) {
    return false;
  }
  // framereserve
  if (lhs->framereserve != rhs->framereserve) {
    return false;
  }
  // sn
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->sn[i] != rhs->sn[i]) {
      return false;
    }
  }
  // version
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->version[i] != rhs->version[i]) {
      return false;
    }
  }
  // bandwidth
  if (lhs->bandwidth != rhs->bandwidth) {
    return false;
  }
  // imu
  if (!unitree_legged_msgs__msg__IMU__are_equal(
      &(lhs->imu), &(rhs->imu)))
  {
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorState__are_equal(
        &(lhs->motor_state[i]), &(rhs->motor_state[i])))
    {
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsState__are_equal(
      &(lhs->bms), &(rhs->bms)))
  {
    return false;
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force[i] != rhs->foot_force[i]) {
      return false;
    }
  }
  // foot_force_est
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force_est[i] != rhs->foot_force_est[i]) {
      return false;
    }
  }
  // tick
  if (lhs->tick != rhs->tick) {
    return false;
  }
  // wireless_remote
  for (size_t i = 0; i < 40; ++i) {
    if (lhs->wireless_remote[i] != rhs->wireless_remote[i]) {
      return false;
    }
  }
  // reserve
  if (lhs->reserve != rhs->reserve) {
    return false;
  }
  // crc
  if (lhs->crc != rhs->crc) {
    return false;
  }
  // ee_force_raw
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__are_equal(
        &(lhs->ee_force_raw[i]), &(rhs->ee_force_raw[i])))
    {
      return false;
    }
  }
  // ee_force
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__are_equal(
        &(lhs->ee_force[i]), &(rhs->ee_force[i])))
    {
      return false;
    }
  }
  // position
  if (!unitree_legged_msgs__msg__Cartesian__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // velocity
  if (!unitree_legged_msgs__msg__Cartesian__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // velocity_w
  if (!unitree_legged_msgs__msg__Cartesian__are_equal(
      &(lhs->velocity_w), &(rhs->velocity_w)))
  {
    return false;
  }
  return true;
}

bool
unitree_legged_msgs__msg__LowState__copy(
  const unitree_legged_msgs__msg__LowState * input,
  unitree_legged_msgs__msg__LowState * output)
{
  if (!input || !output) {
    return false;
  }
  // head
  for (size_t i = 0; i < 2; ++i) {
    output->head[i] = input->head[i];
  }
  // levelflag
  output->levelflag = input->levelflag;
  // framereserve
  output->framereserve = input->framereserve;
  // sn
  for (size_t i = 0; i < 2; ++i) {
    output->sn[i] = input->sn[i];
  }
  // version
  for (size_t i = 0; i < 2; ++i) {
    output->version[i] = input->version[i];
  }
  // bandwidth
  output->bandwidth = input->bandwidth;
  // imu
  if (!unitree_legged_msgs__msg__IMU__copy(
      &(input->imu), &(output->imu)))
  {
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorState__copy(
        &(input->motor_state[i]), &(output->motor_state[i])))
    {
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsState__copy(
      &(input->bms), &(output->bms)))
  {
    return false;
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force[i] = input->foot_force[i];
  }
  // foot_force_est
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force_est[i] = input->foot_force_est[i];
  }
  // tick
  output->tick = input->tick;
  // wireless_remote
  for (size_t i = 0; i < 40; ++i) {
    output->wireless_remote[i] = input->wireless_remote[i];
  }
  // reserve
  output->reserve = input->reserve;
  // crc
  output->crc = input->crc;
  // ee_force_raw
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__copy(
        &(input->ee_force_raw[i]), &(output->ee_force_raw[i])))
    {
      return false;
    }
  }
  // ee_force
  for (size_t i = 0; i < 4; ++i) {
    if (!unitree_legged_msgs__msg__Cartesian__copy(
        &(input->ee_force[i]), &(output->ee_force[i])))
    {
      return false;
    }
  }
  // position
  if (!unitree_legged_msgs__msg__Cartesian__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // velocity
  if (!unitree_legged_msgs__msg__Cartesian__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // velocity_w
  if (!unitree_legged_msgs__msg__Cartesian__copy(
      &(input->velocity_w), &(output->velocity_w)))
  {
    return false;
  }
  return true;
}

unitree_legged_msgs__msg__LowState *
unitree_legged_msgs__msg__LowState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowState * msg = (unitree_legged_msgs__msg__LowState *)allocator.allocate(sizeof(unitree_legged_msgs__msg__LowState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_legged_msgs__msg__LowState));
  bool success = unitree_legged_msgs__msg__LowState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_legged_msgs__msg__LowState__destroy(unitree_legged_msgs__msg__LowState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_legged_msgs__msg__LowState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_legged_msgs__msg__LowState__Sequence__init(unitree_legged_msgs__msg__LowState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowState * data = NULL;

  if (size) {
    data = (unitree_legged_msgs__msg__LowState *)allocator.zero_allocate(size, sizeof(unitree_legged_msgs__msg__LowState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_legged_msgs__msg__LowState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_legged_msgs__msg__LowState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
unitree_legged_msgs__msg__LowState__Sequence__fini(unitree_legged_msgs__msg__LowState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      unitree_legged_msgs__msg__LowState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

unitree_legged_msgs__msg__LowState__Sequence *
unitree_legged_msgs__msg__LowState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowState__Sequence * array = (unitree_legged_msgs__msg__LowState__Sequence *)allocator.allocate(sizeof(unitree_legged_msgs__msg__LowState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_legged_msgs__msg__LowState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_legged_msgs__msg__LowState__Sequence__destroy(unitree_legged_msgs__msg__LowState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_legged_msgs__msg__LowState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_legged_msgs__msg__LowState__Sequence__are_equal(const unitree_legged_msgs__msg__LowState__Sequence * lhs, const unitree_legged_msgs__msg__LowState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_legged_msgs__msg__LowState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_legged_msgs__msg__LowState__Sequence__copy(
  const unitree_legged_msgs__msg__LowState__Sequence * input,
  unitree_legged_msgs__msg__LowState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_legged_msgs__msg__LowState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_legged_msgs__msg__LowState * data =
      (unitree_legged_msgs__msg__LowState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_legged_msgs__msg__LowState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_legged_msgs__msg__LowState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_legged_msgs__msg__LowState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
