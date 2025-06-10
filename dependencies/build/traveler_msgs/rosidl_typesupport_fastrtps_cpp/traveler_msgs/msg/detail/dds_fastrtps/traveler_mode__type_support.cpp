// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/traveler_mode__rosidl_typesupport_fastrtps_cpp.hpp"
#include "traveler_msgs/msg/detail/traveler_mode__functions.h"
#include "traveler_msgs/msg/detail/traveler_mode__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
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
  const traveler_msgs::msg::TravelerMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: start_flag
  cdr << (ros_message.start_flag ? true : false);

  // Member: traveler_mode
  cdr << ros_message.traveler_mode;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  traveler_msgs::msg::TravelerMode & ros_message)
{
  // Member: start_flag
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.start_flag = tmp ? true : false;
  }

  // Member: traveler_mode
  cdr >> ros_message.traveler_mode;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
get_serialized_size(
  const traveler_msgs::msg::TravelerMode & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: start_flag
  {
    size_t item_size = sizeof(ros_message.start_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: traveler_mode
  {
    size_t item_size = sizeof(ros_message.traveler_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
max_serialized_size_TravelerMode(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: start_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: traveler_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = traveler_msgs::msg::TravelerMode;
    is_plain =
      (
      offsetof(DataType, traveler_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
cdr_serialize_key(
  const traveler_msgs::msg::TravelerMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: start_flag
  cdr << (ros_message.start_flag ? true : false);

  // Member: traveler_mode
  cdr << ros_message.traveler_mode;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
get_serialized_size_key(
  const traveler_msgs::msg::TravelerMode & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: start_flag
  {
    size_t item_size = sizeof(ros_message.start_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: traveler_mode
  {
    size_t item_size = sizeof(ros_message.traveler_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_traveler_msgs
max_serialized_size_key_TravelerMode(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: start_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: traveler_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = traveler_msgs::msg::TravelerMode;
    is_plain =
      (
      offsetof(DataType, traveler_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _TravelerMode__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const traveler_msgs::msg::TravelerMode *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TravelerMode__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<traveler_msgs::msg::TravelerMode *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TravelerMode__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const traveler_msgs::msg::TravelerMode *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TravelerMode__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TravelerMode(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TravelerMode__callbacks = {
  "traveler_msgs::msg",
  "TravelerMode",
  _TravelerMode__cdr_serialize,
  _TravelerMode__cdr_deserialize,
  _TravelerMode__get_serialized_size,
  _TravelerMode__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _TravelerMode__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TravelerMode__callbacks,
  get_message_typesupport_handle_function,
  &traveler_msgs__msg__TravelerMode__get_type_hash,
  &traveler_msgs__msg__TravelerMode__get_type_description,
  &traveler_msgs__msg__TravelerMode__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace traveler_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_traveler_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<traveler_msgs::msg::TravelerMode>()
{
  return &traveler_msgs::msg::typesupport_fastrtps_cpp::_TravelerMode__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, traveler_msgs, msg, TravelerMode)() {
  return &traveler_msgs::msg::typesupport_fastrtps_cpp::_TravelerMode__handle;
}

#ifdef __cplusplus
}
#endif
