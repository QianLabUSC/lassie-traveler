// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "traveler_msgs/msg/detail/odrive_status__rosidl_typesupport_introspection_c.h"
#include "traveler_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "traveler_msgs/msg/detail/odrive_status__functions.h"
#include "traveler_msgs/msg/detail/odrive_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  traveler_msgs__msg__OdriveStatus__init(message_memory);
}

void traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_fini_function(void * message_memory)
{
  traveler_msgs__msg__OdriveStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_member_array[6] = {
  {
    "can_channel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, can_channel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_estimate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, pos_estimate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel_estimate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, vel_estimate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "iq_setpoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, iq_setpoint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "iq_measured",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(traveler_msgs__msg__OdriveStatus, iq_measured),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_members = {
  "traveler_msgs__msg",  // message namespace
  "OdriveStatus",  // message name
  6,  // number of fields
  sizeof(traveler_msgs__msg__OdriveStatus),
  false,  // has_any_key_member_
  traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_member_array,  // message members
  traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_type_support_handle = {
  0,
  &traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_members,
  get_message_typesupport_handle_function,
  &traveler_msgs__msg__OdriveStatus__get_type_hash,
  &traveler_msgs__msg__OdriveStatus__get_type_description,
  &traveler_msgs__msg__OdriveStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, traveler_msgs, msg, OdriveStatus)() {
  if (!traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_type_support_handle.typesupport_identifier) {
    traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &traveler_msgs__msg__OdriveStatus__rosidl_typesupport_introspection_c__OdriveStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
