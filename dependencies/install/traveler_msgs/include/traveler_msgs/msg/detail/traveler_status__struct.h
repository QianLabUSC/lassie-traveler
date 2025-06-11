// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_H_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TravelerStatus in the package traveler_msgs.
typedef struct traveler_msgs__msg__TravelerStatus
{
  uint8_t state_flag;
  float time;
  float toeforce_x;
  float toeforce_y;
  float toe_pos_x;
  float toe_pos_y;
  float motor0_pos;
  float motor1_pos;
  float motor0_torque;
  float motor1_torque;
} traveler_msgs__msg__TravelerStatus;

// Struct for a sequence of traveler_msgs__msg__TravelerStatus.
typedef struct traveler_msgs__msg__TravelerStatus__Sequence
{
  traveler_msgs__msg__TravelerStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} traveler_msgs__msg__TravelerStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__STRUCT_H_
