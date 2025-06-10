// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from traveler_msgs:msg/TravelerConfig.idl
// generated code does not contain a copyright notice
#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "traveler_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "traveler_msgs/msg/detail/traveler_config__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_serialize_traveler_msgs__msg__TravelerConfig(
  const traveler_msgs__msg__TravelerConfig * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_deserialize_traveler_msgs__msg__TravelerConfig(
  eprosima::fastcdr::Cdr &,
  traveler_msgs__msg__TravelerConfig * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t get_serialized_size_traveler_msgs__msg__TravelerConfig(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t max_serialized_size_traveler_msgs__msg__TravelerConfig(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_serialize_key_traveler_msgs__msg__TravelerConfig(
  const traveler_msgs__msg__TravelerConfig * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t get_serialized_size_key_traveler_msgs__msg__TravelerConfig(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t max_serialized_size_key_traveler_msgs__msg__TravelerConfig(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, traveler_msgs, msg, TravelerConfig)();

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_CONFIG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
