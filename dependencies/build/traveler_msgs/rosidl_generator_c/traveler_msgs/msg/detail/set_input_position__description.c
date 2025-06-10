// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from traveler_msgs:msg/SetInputPosition.idl
// generated code does not contain a copyright notice

#include "traveler_msgs/msg/detail/set_input_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
const rosidl_type_hash_t *
traveler_msgs__msg__SetInputPosition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5e, 0xaf, 0x4b, 0x8c, 0x46, 0x38, 0x1e, 0x88,
      0x34, 0xd4, 0x83, 0x4c, 0xd2, 0x7b, 0x6d, 0x74,
      0xc4, 0x11, 0x04, 0x9a, 0x30, 0x1f, 0x17, 0x59,
      0xf0, 0x9f, 0xb7, 0x83, 0xba, 0xcf, 0x3a, 0x27,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char traveler_msgs__msg__SetInputPosition__TYPE_NAME[] = "traveler_msgs/msg/SetInputPosition";

// Define type names, field names, and default values
static char traveler_msgs__msg__SetInputPosition__FIELD_NAME__can_channel[] = "can_channel";
static char traveler_msgs__msg__SetInputPosition__FIELD_NAME__axis[] = "axis";
static char traveler_msgs__msg__SetInputPosition__FIELD_NAME__input_position[] = "input_position";
static char traveler_msgs__msg__SetInputPosition__FIELD_NAME__vel_ff[] = "vel_ff";
static char traveler_msgs__msg__SetInputPosition__FIELD_NAME__torque_ff[] = "torque_ff";

static rosidl_runtime_c__type_description__Field traveler_msgs__msg__SetInputPosition__FIELDS[] = {
  {
    {traveler_msgs__msg__SetInputPosition__FIELD_NAME__can_channel, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__SetInputPosition__FIELD_NAME__axis, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__SetInputPosition__FIELD_NAME__input_position, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__SetInputPosition__FIELD_NAME__vel_ff, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__SetInputPosition__FIELD_NAME__torque_ff, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
traveler_msgs__msg__SetInputPosition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {traveler_msgs__msg__SetInputPosition__TYPE_NAME, 34, 34},
      {traveler_msgs__msg__SetInputPosition__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 can_channel\n"
  "uint8 axis\n"
  "float32 input_position\n"
  "int16 vel_ff # 0.1 Factor\n"
  "int16 torque_ff # 0.001 Factor";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
traveler_msgs__msg__SetInputPosition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {traveler_msgs__msg__SetInputPosition__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 109, 109},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
traveler_msgs__msg__SetInputPosition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *traveler_msgs__msg__SetInputPosition__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
