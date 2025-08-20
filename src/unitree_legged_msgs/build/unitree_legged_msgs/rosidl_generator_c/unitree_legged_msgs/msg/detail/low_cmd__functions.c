// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_legged_msgs:msg/LowCmd.idl
// generated code does not contain a copyright notice
#include "unitree_legged_msgs/msg/detail/low_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `motor_cmd`
#include "unitree_legged_msgs/msg/detail/motor_cmd__functions.h"
// Member `bms`
#include "unitree_legged_msgs/msg/detail/bms_cmd__functions.h"

bool
unitree_legged_msgs__msg__LowCmd__init(unitree_legged_msgs__msg__LowCmd * msg)
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
  // motor_cmd
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorCmd__init(&msg->motor_cmd[i])) {
      unitree_legged_msgs__msg__LowCmd__fini(msg);
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsCmd__init(&msg->bms)) {
    unitree_legged_msgs__msg__LowCmd__fini(msg);
    return false;
  }
  // wireless_remote
  // reserve
  // crc
  return true;
}

void
unitree_legged_msgs__msg__LowCmd__fini(unitree_legged_msgs__msg__LowCmd * msg)
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
  // motor_cmd
  for (size_t i = 0; i < 20; ++i) {
    unitree_legged_msgs__msg__MotorCmd__fini(&msg->motor_cmd[i]);
  }
  // bms
  unitree_legged_msgs__msg__BmsCmd__fini(&msg->bms);
  // wireless_remote
  // reserve
  // crc
}

bool
unitree_legged_msgs__msg__LowCmd__are_equal(const unitree_legged_msgs__msg__LowCmd * lhs, const unitree_legged_msgs__msg__LowCmd * rhs)
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
  // motor_cmd
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorCmd__are_equal(
        &(lhs->motor_cmd[i]), &(rhs->motor_cmd[i])))
    {
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsCmd__are_equal(
      &(lhs->bms), &(rhs->bms)))
  {
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
  return true;
}

bool
unitree_legged_msgs__msg__LowCmd__copy(
  const unitree_legged_msgs__msg__LowCmd * input,
  unitree_legged_msgs__msg__LowCmd * output)
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
  // motor_cmd
  for (size_t i = 0; i < 20; ++i) {
    if (!unitree_legged_msgs__msg__MotorCmd__copy(
        &(input->motor_cmd[i]), &(output->motor_cmd[i])))
    {
      return false;
    }
  }
  // bms
  if (!unitree_legged_msgs__msg__BmsCmd__copy(
      &(input->bms), &(output->bms)))
  {
    return false;
  }
  // wireless_remote
  for (size_t i = 0; i < 40; ++i) {
    output->wireless_remote[i] = input->wireless_remote[i];
  }
  // reserve
  output->reserve = input->reserve;
  // crc
  output->crc = input->crc;
  return true;
}

unitree_legged_msgs__msg__LowCmd *
unitree_legged_msgs__msg__LowCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowCmd * msg = (unitree_legged_msgs__msg__LowCmd *)allocator.allocate(sizeof(unitree_legged_msgs__msg__LowCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_legged_msgs__msg__LowCmd));
  bool success = unitree_legged_msgs__msg__LowCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_legged_msgs__msg__LowCmd__destroy(unitree_legged_msgs__msg__LowCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_legged_msgs__msg__LowCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_legged_msgs__msg__LowCmd__Sequence__init(unitree_legged_msgs__msg__LowCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowCmd * data = NULL;

  if (size) {
    data = (unitree_legged_msgs__msg__LowCmd *)allocator.zero_allocate(size, sizeof(unitree_legged_msgs__msg__LowCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_legged_msgs__msg__LowCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_legged_msgs__msg__LowCmd__fini(&data[i - 1]);
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
unitree_legged_msgs__msg__LowCmd__Sequence__fini(unitree_legged_msgs__msg__LowCmd__Sequence * array)
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
      unitree_legged_msgs__msg__LowCmd__fini(&array->data[i]);
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

unitree_legged_msgs__msg__LowCmd__Sequence *
unitree_legged_msgs__msg__LowCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__LowCmd__Sequence * array = (unitree_legged_msgs__msg__LowCmd__Sequence *)allocator.allocate(sizeof(unitree_legged_msgs__msg__LowCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_legged_msgs__msg__LowCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_legged_msgs__msg__LowCmd__Sequence__destroy(unitree_legged_msgs__msg__LowCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_legged_msgs__msg__LowCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_legged_msgs__msg__LowCmd__Sequence__are_equal(const unitree_legged_msgs__msg__LowCmd__Sequence * lhs, const unitree_legged_msgs__msg__LowCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_legged_msgs__msg__LowCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_legged_msgs__msg__LowCmd__Sequence__copy(
  const unitree_legged_msgs__msg__LowCmd__Sequence * input,
  unitree_legged_msgs__msg__LowCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_legged_msgs__msg__LowCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_legged_msgs__msg__LowCmd * data =
      (unitree_legged_msgs__msg__LowCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_legged_msgs__msg__LowCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_legged_msgs__msg__LowCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_legged_msgs__msg__LowCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
