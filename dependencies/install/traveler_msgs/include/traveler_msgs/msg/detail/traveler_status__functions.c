// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/traveler_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
traveler_msgs__msg__TravelerStatus__init(traveler_msgs__msg__TravelerStatus * msg)
{
  if (!msg) {
    return false;
  }
  // state_flag
  // time
  // toeforce_x
  // toeforce_y
  // toe_pos_x
  // toe_pos_y
  // motor0_pos
  // motor1_pos
  // motor0_torque
  // motor1_torque
  return true;
}

void
traveler_msgs__msg__TravelerStatus__fini(traveler_msgs__msg__TravelerStatus * msg)
{
  if (!msg) {
    return;
  }
  // state_flag
  // time
  // toeforce_x
  // toeforce_y
  // toe_pos_x
  // toe_pos_y
  // motor0_pos
  // motor1_pos
  // motor0_torque
  // motor1_torque
}

bool
traveler_msgs__msg__TravelerStatus__are_equal(const traveler_msgs__msg__TravelerStatus * lhs, const traveler_msgs__msg__TravelerStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state_flag
  if (lhs->state_flag != rhs->state_flag) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // toeforce_x
  if (lhs->toeforce_x != rhs->toeforce_x) {
    return false;
  }
  // toeforce_y
  if (lhs->toeforce_y != rhs->toeforce_y) {
    return false;
  }
  // toe_pos_x
  if (lhs->toe_pos_x != rhs->toe_pos_x) {
    return false;
  }
  // toe_pos_y
  if (lhs->toe_pos_y != rhs->toe_pos_y) {
    return false;
  }
  // motor0_pos
  if (lhs->motor0_pos != rhs->motor0_pos) {
    return false;
  }
  // motor1_pos
  if (lhs->motor1_pos != rhs->motor1_pos) {
    return false;
  }
  // motor0_torque
  if (lhs->motor0_torque != rhs->motor0_torque) {
    return false;
  }
  // motor1_torque
  if (lhs->motor1_torque != rhs->motor1_torque) {
    return false;
  }
  return true;
}

bool
traveler_msgs__msg__TravelerStatus__copy(
  const traveler_msgs__msg__TravelerStatus * input,
  traveler_msgs__msg__TravelerStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // state_flag
  output->state_flag = input->state_flag;
  // time
  output->time = input->time;
  // toeforce_x
  output->toeforce_x = input->toeforce_x;
  // toeforce_y
  output->toeforce_y = input->toeforce_y;
  // toe_pos_x
  output->toe_pos_x = input->toe_pos_x;
  // toe_pos_y
  output->toe_pos_y = input->toe_pos_y;
  // motor0_pos
  output->motor0_pos = input->motor0_pos;
  // motor1_pos
  output->motor1_pos = input->motor1_pos;
  // motor0_torque
  output->motor0_torque = input->motor0_torque;
  // motor1_torque
  output->motor1_torque = input->motor1_torque;
  return true;
}

traveler_msgs__msg__TravelerStatus *
traveler_msgs__msg__TravelerStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerStatus * msg = (traveler_msgs__msg__TravelerStatus *)allocator.allocate(sizeof(traveler_msgs__msg__TravelerStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(traveler_msgs__msg__TravelerStatus));
  bool success = traveler_msgs__msg__TravelerStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
traveler_msgs__msg__TravelerStatus__destroy(traveler_msgs__msg__TravelerStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    traveler_msgs__msg__TravelerStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
traveler_msgs__msg__TravelerStatus__Sequence__init(traveler_msgs__msg__TravelerStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerStatus * data = NULL;

  if (size) {
    data = (traveler_msgs__msg__TravelerStatus *)allocator.zero_allocate(size, sizeof(traveler_msgs__msg__TravelerStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = traveler_msgs__msg__TravelerStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        traveler_msgs__msg__TravelerStatus__fini(&data[i - 1]);
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
traveler_msgs__msg__TravelerStatus__Sequence__fini(traveler_msgs__msg__TravelerStatus__Sequence * array)
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
      traveler_msgs__msg__TravelerStatus__fini(&array->data[i]);
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

traveler_msgs__msg__TravelerStatus__Sequence *
traveler_msgs__msg__TravelerStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  traveler_msgs__msg__TravelerStatus__Sequence * array = (traveler_msgs__msg__TravelerStatus__Sequence *)allocator.allocate(sizeof(traveler_msgs__msg__TravelerStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = traveler_msgs__msg__TravelerStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
traveler_msgs__msg__TravelerStatus__Sequence__destroy(traveler_msgs__msg__TravelerStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    traveler_msgs__msg__TravelerStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
traveler_msgs__msg__TravelerStatus__Sequence__are_equal(const traveler_msgs__msg__TravelerStatus__Sequence * lhs, const traveler_msgs__msg__TravelerStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!traveler_msgs__msg__TravelerStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
traveler_msgs__msg__TravelerStatus__Sequence__copy(
  const traveler_msgs__msg__TravelerStatus__Sequence * input,
  traveler_msgs__msg__TravelerStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(traveler_msgs__msg__TravelerStatus);
    traveler_msgs__msg__TravelerStatus * data =
      (traveler_msgs__msg__TravelerStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!traveler_msgs__msg__TravelerStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          traveler_msgs__msg__TravelerStatus__fini(&data[i]);
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
    if (!traveler_msgs__msg__TravelerStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
