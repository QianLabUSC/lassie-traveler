// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_H_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TravelerMode in the package traveler_msgs.
typedef struct traveler_msgs__msg__TravelerMode
{
  bool start_flag;
  int8_t traveler_mode;
} traveler_msgs__msg__TravelerMode;

// Struct for a sequence of traveler_msgs__msg__TravelerMode.
typedef struct traveler_msgs__msg__TravelerMode__Sequence
{
  traveler_msgs__msg__TravelerMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} traveler_msgs__msg__TravelerMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_H_
