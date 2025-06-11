// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/traveler_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
traveler_msgs__msg__TravelerMode__init(traveler_msgs__msg__TravelerMode * msg)
{
  if (!msg) {
    return false;
  }
  // start_flag
  // traveler_mode
  return true;
}

void
traveler_msgs__msg__TravelerMode__fini(traveler_msgs__msg__TravelerMode * msg)
{
  if (!msg) {
    return;
  }
  // start_flag
  // traveler_mode
}

bool
traveler_msgs__msg__TravelerMode__are_equal(const traveler_msgs__msg__TravelerMode * lhs, const traveler_msgs__msg__TravelerMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_flag
  if (lhs->start_flag != rhs->start_flag) {
    return false;
  }
  // traveler_mode
  if (lhs->traveler_mode != rhs->traveler_mode) {
    return false;
  }
  return true;
}

bool
traveler_msgs__msg__TravelerMode__copy(
  const traveler_msgs__msg__TravelerMode * input,
  traveler_msgs__msg__TravelerMode * output)
{
  if (!input || !output) {
    return false;
  }
  // start_flag
  output->start_flag = input->start_flag;
  // traveler_mode
  output->traveler_mode = input->traveler_mode;
  return true;
}

traveler_msgs__msg__TravelerMode *
traveler_msgs__msg__TravelerMode__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerMode * msg = (traveler_msgs__msg__TravelerMode *)allocator.allocate(sizeof(traveler_msgs__msg__TravelerMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(traveler_msgs__msg__TravelerMode));
  bool success = traveler_msgs__msg__TravelerMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
traveler_msgs__msg__TravelerMode__destroy(traveler_msgs__msg__TravelerMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    traveler_msgs__msg__TravelerMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
traveler_msgs__msg__TravelerMode__Sequence__init(traveler_msgs__msg__TravelerMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerMode * data = NULL;

  if (size) {
    data = (traveler_msgs__msg__TravelerMode *)allocator.zero_allocate(size, sizeof(traveler_msgs__msg__TravelerMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = traveler_msgs__msg__TravelerMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        traveler_msgs__msg__TravelerMode__fini(&data[i - 1]);
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
traveler_msgs__msg__TravelerMode__Sequence__fini(traveler_msgs__msg__TravelerMode__Sequence * array)
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
      traveler_msgs__msg__TravelerMode__fini(&array->data[i]);
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

traveler_msgs__msg__TravelerMode__Sequence *
traveler_msgs__msg__TravelerMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerMode__Sequence * array = (traveler_msgs__msg__TravelerMode__Sequence *)allocator.allocate(sizeof(traveler_msgs__msg__TravelerMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = traveler_msgs__msg__TravelerMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
traveler_msgs__msg__TravelerMode__Sequence__destroy(traveler_msgs__msg__TravelerMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    traveler_msgs__msg__TravelerMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
traveler_msgs__msg__TravelerMode__Sequence__are_equal(const traveler_msgs__msg__TravelerMode__Sequence * lhs, const traveler_msgs__msg__TravelerMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!traveler_msgs__msg__TravelerMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
traveler_msgs__msg__TravelerMode__Sequence__copy(
  const traveler_msgs__msg__TravelerMode__Sequence * input,
  traveler_msgs__msg__TravelerMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(traveler_msgs__msg__TravelerMode);
    traveler_msgs__msg__TravelerMode * data =
      (traveler_msgs__msg__TravelerMode *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!traveler_msgs__msg__TravelerMode__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          traveler_msgs__msg__TravelerMode__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!traveler_msgs__msg__TravelerMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
