// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/odrive_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
traveler_msgs__msg__OdriveStatus__init(traveler_msgs__msg__OdriveStatus * msg)
{
  if (!msg) {
    return false;
  }
  // can_channel
  // axis
  // pos_estimate
  // vel_estimate
  // iq_setpoint
  // iq_measured
  return true;
}

void
traveler_msgs__msg__OdriveStatus__fini(traveler_msgs__msg__OdriveStatus * msg)
{
  if (!msg) {
    return;
  }
  // can_channel
  // axis
  // pos_estimate
  // vel_estimate
  // iq_setpoint
  // iq_measured
}

bool
traveler_msgs__msg__OdriveStatus__are_equal(const traveler_msgs__msg__OdriveStatus * lhs, const traveler_msgs__msg__OdriveStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // can_channel
  if (lhs->can_channel != rhs->can_channel) {
    return false;
  }
  // axis
  if (lhs->axis != rhs->axis) {
    return false;
  }
  // pos_estimate
  if (lhs->pos_estimate != rhs->pos_estimate) {
    return false;
  }
  // vel_estimate
  if (lhs->vel_estimate != rhs->vel_estimate) {
    return false;
  }
  // iq_setpoint
  if (lhs->iq_setpoint != rhs->iq_setpoint) {
    return false;
  }
  // iq_measured
  if (lhs->iq_measured != rhs->iq_measured) {
    return false;
  }
  return true;
}

bool
traveler_msgs__msg__OdriveStatus__copy(
  const traveler_msgs__msg__OdriveStatus * input,
  traveler_msgs__msg__OdriveStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // can_channel
  output->can_channel = input->can_channel;
  // axis
  output->axis = input->axis;
  // pos_estimate
  output->pos_estimate = input->pos_estimate;
  // vel_estimate
  output->vel_estimate = input->vel_estimate;
  // iq_setpoint
  output->iq_setpoint = input->iq_setpoint;
  // iq_measured
  output->iq_measured = input->iq_measured;
  return true;
}

traveler_msgs__msg__OdriveStatus *
traveler_msgs__msg__OdriveStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__OdriveStatus * msg = (traveler_msgs__msg__OdriveStatus *)allocator.allocate(sizeof(traveler_msgs__msg__OdriveStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(traveler_msgs__msg__OdriveStatus));
  bool success = traveler_msgs__msg__OdriveStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
traveler_msgs__msg__OdriveStatus__destroy(traveler_msgs__msg__OdriveStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    traveler_msgs__msg__OdriveStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
traveler_msgs__msg__OdriveStatus__Sequence__init(traveler_msgs__msg__OdriveStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__OdriveStatus * data = NULL;

  if (size) {
    data = (traveler_msgs__msg__OdriveStatus *)allocator.zero_allocate(size, sizeof(traveler_msgs__msg__OdriveStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = traveler_msgs__msg__OdriveStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        traveler_msgs__msg__OdriveStatus__fini(&data[i - 1]);
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
traveler_msgs__msg__OdriveStatus__Sequence__fini(traveler_msgs__msg__OdriveStatus__Sequence * array)
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
      traveler_msgs__msg__OdriveStatus__fini(&array->data[i]);
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

traveler_msgs__msg__OdriveStatus__Sequence *
traveler_msgs__msg__OdriveStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__OdriveStatus__Sequence * array = (traveler_msgs__msg__OdriveStatus__Sequence *)allocator.allocate(sizeof(traveler_msgs__msg__OdriveStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = traveler_msgs__msg__OdriveStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
traveler_msgs__msg__OdriveStatus__Sequence__destroy(traveler_msgs__msg__OdriveStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    traveler_msgs__msg__OdriveStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
traveler_msgs__msg__OdriveStatus__Sequence__are_equal(const traveler_msgs__msg__OdriveStatus__Sequence * lhs, const traveler_msgs__msg__OdriveStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!traveler_msgs__msg__OdriveStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
traveler_msgs__msg__OdriveStatus__Sequence__copy(
  const traveler_msgs__msg__OdriveStatus__Sequence * input,
  traveler_msgs__msg__OdriveStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(traveler_msgs__msg__OdriveStatus);
    traveler_msgs__msg__OdriveStatus * data =
      (traveler_msgs__msg__OdriveStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!traveler_msgs__msg__OdriveStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          traveler_msgs__msg__OdriveStatus__fini(&data[i]);
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
    if (!traveler_msgs__msg__OdriveStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
