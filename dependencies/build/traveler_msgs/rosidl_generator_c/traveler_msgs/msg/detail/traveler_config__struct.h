// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "traveler_msgs/msg/traveler_config.h"


#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_H_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'running_scenario'
// Member 'filename'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TravelerConfig in the package traveler_msgs.
typedef struct traveler_msgs__msg__TravelerConfig
{
  /// Currently unused
  rosidl_runtime_c__String running_scenario;
  /// Currently unused
  rosidl_runtime_c__String filename;
  /// This is the type of mode
  int8_t traveler_mode;
  /// This is the trajectory data associated with the mode
  rosidl_runtime_c__float__Sequence data;
} traveler_msgs__msg__TravelerConfig;

// Struct for a sequence of traveler_msgs__msg__TravelerConfig.
typedef struct traveler_msgs__msg__TravelerConfig__Sequence
{
  traveler_msgs__msg__TravelerConfig * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} traveler_msgs__msg__TravelerConfig__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__STRUCT_H_
