// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

#include "traveler_msgs/msg/detail/odrive_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
const rosidl_type_hash_t *
traveler_msgs__msg__OdriveStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdf, 0xd2, 0x1a, 0x98, 0xdf, 0xae, 0x6d, 0xff,
      0xbb, 0x94, 0xc0, 0x12, 0x35, 0x19, 0x05, 0xaa,
      0x96, 0xbf, 0xad, 0x2d, 0xa1, 0x1c, 0x2b, 0x98,
      0xb7, 0x08, 0x64, 0xb9, 0x02, 0x5d, 0xab, 0x3c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char traveler_msgs__msg__OdriveStatus__TYPE_NAME[] = "traveler_msgs/msg/OdriveStatus";

// Define type names, field names, and default values
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__can_channel[] = "can_channel";
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__axis[] = "axis";
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__pos_estimate[] = "pos_estimate";
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__vel_estimate[] = "vel_estimate";
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__iq_setpoint[] = "iq_setpoint";
static char traveler_msgs__msg__OdriveStatus__FIELD_NAME__iq_measured[] = "iq_measured";

static rosidl_runtime_c__type_description__Field traveler_msgs__msg__OdriveStatus__FIELDS[] = {
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__can_channel, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__axis, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__pos_estimate, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__vel_estimate, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__iq_setpoint, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {traveler_msgs__msg__OdriveStatus__FIELD_NAME__iq_measured, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
traveler_msgs__msg__OdriveStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {traveler_msgs__msg__OdriveStatus__TYPE_NAME, 30, 30},
      {traveler_msgs__msg__OdriveStatus__FIELDS, 6, 6},
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
  "float32 pos_estimate\n"
  "float32 vel_estimate\n"
  "float32 iq_setpoint\n"
  "float32 iq_measured";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
traveler_msgs__msg__OdriveStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {traveler_msgs__msg__OdriveStatus__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 111, 111},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
traveler_msgs__msg__OdriveStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *traveler_msgs__msg__OdriveStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
