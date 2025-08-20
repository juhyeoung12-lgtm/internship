// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_legged_msgs:msg/BmsCmd.idl
// generated code does not contain a copyright notice
#include "unitree_legged_msgs/msg/detail/bms_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
unitree_legged_msgs__msg__BmsCmd__init(unitree_legged_msgs__msg__BmsCmd * msg)
{
  if (!msg) {
    return false;
  }
  // off
  // reserve
  return true;
}

void
unitree_legged_msgs__msg__BmsCmd__fini(unitree_legged_msgs__msg__BmsCmd * msg)
{
  if (!msg) {
    return;
  }
  // off
  // reserve
}

bool
unitree_legged_msgs__msg__BmsCmd__are_equal(const unitree_legged_msgs__msg__BmsCmd * lhs, const unitree_legged_msgs__msg__BmsCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // off
  if (lhs->off != rhs->off) {
    return false;
  }
  // reserve
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->reserve[i] != rhs->reserve[i]) {
      return false;
    }
  }
  return true;
}

bool
unitree_legged_msgs__msg__BmsCmd__copy(
  const unitree_legged_msgs__msg__BmsCmd * input,
  unitree_legged_msgs__msg__BmsCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // off
  output->off = input->off;
  // reserve
  for (size_t i = 0; i < 3; ++i) {
    output->reserve[i] = input->reserve[i];
  }
  return true;
}

unitree_legged_msgs__msg__BmsCmd *
unitree_legged_msgs__msg__BmsCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__BmsCmd * msg = (unitree_legged_msgs__msg__BmsCmd *)allocator.allocate(sizeof(unitree_legged_msgs__msg__BmsCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_legged_msgs__msg__BmsCmd));
  bool success = unitree_legged_msgs__msg__BmsCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_legged_msgs__msg__BmsCmd__destroy(unitree_legged_msgs__msg__BmsCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_legged_msgs__msg__BmsCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_legged_msgs__msg__BmsCmd__Sequence__init(unitree_legged_msgs__msg__BmsCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__BmsCmd * data = NULL;

  if (size) {
    data = (unitree_legged_msgs__msg__BmsCmd *)allocator.zero_allocate(size, sizeof(unitree_legged_msgs__msg__BmsCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_legged_msgs__msg__BmsCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_legged_msgs__msg__BmsCmd__fini(&data[i - 1]);
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
unitree_legged_msgs__msg__BmsCmd__Sequence__fini(unitree_legged_msgs__msg__BmsCmd__Sequence * array)
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
      unitree_legged_msgs__msg__BmsCmd__fini(&array->data[i]);
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

unitree_legged_msgs__msg__BmsCmd__Sequence *
unitree_legged_msgs__msg__BmsCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_legged_msgs__msg__BmsCmd__Sequence * array = (unitree_legged_msgs__msg__BmsCmd__Sequence *)allocator.allocate(sizeof(unitree_legged_msgs__msg__BmsCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_legged_msgs__msg__BmsCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_legged_msgs__msg__BmsCmd__Sequence__destroy(unitree_legged_msgs__msg__BmsCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_legged_msgs__msg__BmsCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_legged_msgs__msg__BmsCmd__Sequence__are_equal(const unitree_legged_msgs__msg__BmsCmd__Sequence * lhs, const unitree_legged_msgs__msg__BmsCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_legged_msgs__msg__BmsCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_legged_msgs__msg__BmsCmd__Sequence__copy(
  const unitree_legged_msgs__msg__BmsCmd__Sequence * input,
  unitree_legged_msgs__msg__BmsCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_legged_msgs__msg__BmsCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_legged_msgs__msg__BmsCmd * data =
      (unitree_legged_msgs__msg__BmsCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_legged_msgs__msg__BmsCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_legged_msgs__msg__BmsCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_legged_msgs__msg__BmsCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
