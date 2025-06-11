// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_H_
#define TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/OdriveStatus in the package traveler_msgs.
typedef struct traveler_msgs__msg__OdriveStatus
{
  uint8_t can_channel;
  uint8_t axis;
  float pos_estimate;
  float vel_estimate;
  float iq_setpoint;
  float iq_measured;
} traveler_msgs__msg__OdriveStatus;

// Struct for a sequence of traveler_msgs__msg__OdriveStatus.
typedef struct traveler_msgs__msg__OdriveStatus__Sequence
{
  traveler_msgs__msg__OdriveStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} traveler_msgs__msg__OdriveStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_H_
