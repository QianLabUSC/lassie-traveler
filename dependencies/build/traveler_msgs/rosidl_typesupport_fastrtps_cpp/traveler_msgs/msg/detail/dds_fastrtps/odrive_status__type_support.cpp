// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/odrive_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "traveler_msgs/msg/detail/odrive_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace traveler_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
cdr_serialize(
  const traveler_msgs::msg::OdriveStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: can_channel
  cdr << ros_message.can_channel;
  // Member: axis
  cdr << ros_message.axis;
  // Member: pos_estimate
  cdr << ros_message.pos_estimate;
  // Member: vel_estimate
  cdr << ros_message.vel_estimate;
  // Member: iq_setpoint
  cdr << ros_message.iq_setpoint;
  // Member: iq_measured
  cdr << ros_message.iq_measured;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  traveler_msgs::msg::OdriveStatus & ros_message)
{
  // Member: can_channel
  cdr >> ros_message.can_channel;

  // Member: axis
  cdr >> ros_message.axis;

  // Member: pos_estimate
  cdr >> ros_message.pos_estimate;

  // Member: vel_estimate
  cdr >> ros_message.vel_estimate;

  // Member: iq_setpoint
  cdr >> ros_message.iq_setpoint;

  // Member: iq_measured
  cdr >> ros_message.iq_measured;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
get_serialized_size(
  const traveler_msgs::msg::OdriveStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: can_channel
  {
    size_t item_size = sizeof(ros_message.can_channel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: axis
  {
    size_t item_size = sizeof(ros_message.axis);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_estimate
  {
    size_t item_size = sizeof(ros_message.pos_estimate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_estimate
  {
    size_t item_size = sizeof(ros_message.vel_estimate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iq_setpoint
  {
    size_t item_size = sizeof(ros_message.iq_setpoint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iq_measured
  {
    size_t item_size = sizeof(ros_message.iq_measured);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
max_serialized_size_OdriveStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: can_channel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: axis
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pos_estimate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_estimate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iq_setpoint
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iq_measured
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _OdriveStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const traveler_msgs::msg::OdriveStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _OdriveStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<traveler_msgs::msg::OdriveStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _OdriveStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const traveler_msgs::msg::OdriveStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _OdriveStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_OdriveStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _OdriveStatus__callbacks = {
  "traveler_msgs::msg",
  "OdriveStatus",
  _OdriveStatus__cdr_serialize,
  _OdriveStatus__cdr_deserialize,
  _OdriveStatus__get_serialized_size,
  _OdriveStatus__max_serialized_size
};

static rosidl_message_type_support_t _OdriveStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OdriveStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace traveler_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<traveler_msgs::msg::OdriveStatus>()
{
  return &traveler_msgs::msg::typesupport_fastrtps_cpp::_OdriveStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, traveler_msgs, msg, OdriveStatus)() {
  return &traveler_msgs::msg::typesupport_fastrtps_cpp::_OdriveStatus__handle;
}

#ifdef __cplusplus
}
#endif
