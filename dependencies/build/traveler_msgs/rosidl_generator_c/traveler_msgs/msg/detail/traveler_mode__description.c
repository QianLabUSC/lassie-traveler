// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#include "traveler_msgs/msg/detail/traveler_mode__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
const rosidl_type_hash_t *
traveler_msgs__msg__TravelerMode__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0x69, 0xe0, 0x67, 0x1a, 0x30, 0x77, 0xad,
      0xb9, 0xc6, 0x29, 0xdc, 0x4d, 0x4c, 0xa2, 0x66,
      0x57, 0xae, 0x5b, 0xad, 0xb7, 0xf7, 0xdf, 0x7c,
      0xd8, 0xe9, 0x94, 0xa9, 0x55, 0x5c, 0x46, 0x78,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char traveler_msgs__msg__TravelerMode__TYPE_NAME[] = "traveler_msgs/msg/TravelerMode";

// Define type names, field names, and default values
static char traveler_msgs__msg__TravelerMode__FIELD_NAME__start_flag[] = "start_flag";
static char traveler_msgs__msg__TravelerMode__FIELD_NAME__traveler_mode[] = "traveler_mode";

static rosidl_runtime_c__type_description__Field traveler_msgs__msg__TravelerMode__FIELDS[] = {
  {
    {traveler_msgs__msg__TravelerMode__FIELD_NAME__start_flag, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__TravelerMode__FIELD_NAME__traveler_mode, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
traveler_msgs__msg__TravelerMode__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {traveler_msgs__msg__TravelerMode__TYPE_NAME, 30, 30},
      {traveler_msgs__msg__TravelerMode__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool start_flag\n"
  "int8 traveler_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
traveler_msgs__msg__TravelerMode__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {traveler_msgs__msg__TravelerMode__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 34, 34},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
traveler_msgs__msg__TravelerMode__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *traveler_msgs__msg__TravelerMode__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
