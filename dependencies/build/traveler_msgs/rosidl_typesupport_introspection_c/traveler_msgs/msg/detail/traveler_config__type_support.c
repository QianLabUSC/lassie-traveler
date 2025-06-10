// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "traveler_msgs/msg/detail/traveler_config__rosidl_typesupport_introspection_c.h"
#include "traveler_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "traveler_msgs/msg/detail/traveler_config__functions.h"
#include "traveler_msgs/msg/detail/traveler_config__struct.h"


// Include directives for member types
// Member `running_scenario`
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  traveler_msgs__msg__TravelerConfig__init(message_memory);
}

void traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_fini_function(void * message_memory)
{
  traveler_msgs__msg__TravelerConfig__fini(message_memory);
}

size_t traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__size_function__TravelerConfig__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_const_function__TravelerConfig__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_function__TravelerConfig__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__fetch_function__TravelerConfig__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_const_function__TravelerConfig__data(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__assign_function__TravelerConfig__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_function__TravelerConfig__data(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__resize_function__TravelerConfig__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_member_array[4] = {
  {
    "running_scenario",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, running_scenario),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "filename",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, filename),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "traveler_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, traveler_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__TravelerConfig, data),  // bytes offset in struct
    NULL,  // default value
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__size_function__TravelerConfig__data,  // size() function pointer
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_const_function__TravelerConfig__data,  // get_const(index) function pointer
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__get_function__TravelerConfig__data,  // get(index) function pointer
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__fetch_function__TravelerConfig__data,  // fetch(index, &value) function pointer
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__assign_function__TravelerConfig__data,  // assign(index, value) function pointer
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__resize_function__TravelerConfig__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_members = {
  "traveler_msgs__msg",  // message namespace
  "TravelerConfig",  // message name
  4,  // number of fields
  sizeof(traveler_msgs__msg__TravelerConfig),
  false,  // has_any_key_member_
  traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_member_array,  // message members
  traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle = {
  0,
  &traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_members,
  get_message_typesupport_handle_function,
  &traveler_msgs__msg__TravelerConfig__get_type_hash,
  &traveler_msgs__msg__TravelerConfig__get_type_description,
  &traveler_msgs__msg__TravelerConfig__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, traveler_msgs, msg, TravelerConfig)() {
  if (!traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle.typesupport_identifier) {
    traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &traveler_msgs__msg__TravelerConfig__rosidl_typesupport_introspection_c__TravelerConfig_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
