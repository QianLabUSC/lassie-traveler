// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/traveler_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "traveler_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "traveler_msgs/msg/detail/traveler_status__struct.h"
#include "traveler_msgs/msg/detail/traveler_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _TravelerStatus__ros_msg_type = traveler_msgs__msg__TravelerStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_serialize_traveler_msgs__msg__TravelerStatus(
  const traveler_msgs__msg__TravelerStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: state_flag
  {
    cdr << ros_message->state_flag;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: toeforce_x
  {
    cdr << ros_message->toeforce_x;
  }

  // Field name: toeforce_y
  {
    cdr << ros_message->toeforce_y;
  }

  // Field name: toe_pos_x
  {
    cdr << ros_message->toe_pos_x;
  }

  // Field name: toe_pos_y
  {
    cdr << ros_message->toe_pos_y;
  }

  // Field name: motor0_pos
  {
    cdr << ros_message->motor0_pos;
  }

  // Field name: motor1_pos
  {
    cdr << ros_message->motor1_pos;
  }

  // Field name: motor0_torque
  {
    cdr << ros_message->motor0_torque;
  }

  // Field name: motor1_torque
  {
    cdr << ros_message->motor1_torque;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_deserialize_traveler_msgs__msg__TravelerStatus(
  eprosima::fastcdr::Cdr & cdr,
  traveler_msgs__msg__TravelerStatus * ros_message)
{
  // Field name: state_flag
  {
    cdr >> ros_message->state_flag;
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: toeforce_x
  {
    cdr >> ros_message->toeforce_x;
  }

  // Field name: toeforce_y
  {
    cdr >> ros_message->toeforce_y;
  }

  // Field name: toe_pos_x
  {
    cdr >> ros_message->toe_pos_x;
  }

  // Field name: toe_pos_y
  {
    cdr >> ros_message->toe_pos_y;
  }

  // Field name: motor0_pos
  {
    cdr >> ros_message->motor0_pos;
  }

  // Field name: motor1_pos
  {
    cdr >> ros_message->motor1_pos;
  }

  // Field name: motor0_torque
  {
    cdr >> ros_message->motor0_torque;
  }

  // Field name: motor1_torque
  {
    cdr >> ros_message->motor1_torque;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t get_serialized_size_traveler_msgs__msg__TravelerStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TravelerStatus__ros_msg_type * ros_message = static_cast<const _TravelerStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: state_flag
  {
    size_t item_size = sizeof(ros_message->state_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toeforce_x
  {
    size_t item_size = sizeof(ros_message->toeforce_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toeforce_y
  {
    size_t item_size = sizeof(ros_message->toeforce_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toe_pos_x
  {
    size_t item_size = sizeof(ros_message->toe_pos_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toe_pos_y
  {
    size_t item_size = sizeof(ros_message->toe_pos_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor0_pos
  {
    size_t item_size = sizeof(ros_message->motor0_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor1_pos
  {
    size_t item_size = sizeof(ros_message->motor1_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor0_torque
  {
    size_t item_size = sizeof(ros_message->motor0_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor1_torque
  {
    size_t item_size = sizeof(ros_message->motor1_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t max_serialized_size_traveler_msgs__msg__TravelerStatus(
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

  // Field name: state_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toeforce_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toeforce_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toe_pos_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toe_pos_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor0_pos
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor1_pos
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor0_torque
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor1_torque
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = traveler_msgs__msg__TravelerStatus;
    is_plain =
      (
      offsetof(DataType, motor1_torque) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
bool cdr_serialize_key_traveler_msgs__msg__TravelerStatus(
  const traveler_msgs__msg__TravelerStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: state_flag
  {
    cdr << ros_message->state_flag;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: toeforce_x
  {
    cdr << ros_message->toeforce_x;
  }

  // Field name: toeforce_y
  {
    cdr << ros_message->toeforce_y;
  }

  // Field name: toe_pos_x
  {
    cdr << ros_message->toe_pos_x;
  }

  // Field name: toe_pos_y
  {
    cdr << ros_message->toe_pos_y;
  }

  // Field name: motor0_pos
  {
    cdr << ros_message->motor0_pos;
  }

  // Field name: motor1_pos
  {
    cdr << ros_message->motor1_pos;
  }

  // Field name: motor0_torque
  {
    cdr << ros_message->motor0_torque;
  }

  // Field name: motor1_torque
  {
    cdr << ros_message->motor1_torque;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t get_serialized_size_key_traveler_msgs__msg__TravelerStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TravelerStatus__ros_msg_type * ros_message = static_cast<const _TravelerStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: state_flag
  {
    size_t item_size = sizeof(ros_message->state_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toeforce_x
  {
    size_t item_size = sizeof(ros_message->toeforce_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toeforce_y
  {
    size_t item_size = sizeof(ros_message->toeforce_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toe_pos_x
  {
    size_t item_size = sizeof(ros_message->toe_pos_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: toe_pos_y
  {
    size_t item_size = sizeof(ros_message->toe_pos_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor0_pos
  {
    size_t item_size = sizeof(ros_message->motor0_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor1_pos
  {
    size_t item_size = sizeof(ros_message->motor1_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor0_torque
  {
    size_t item_size = sizeof(ros_message->motor0_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: motor1_torque
  {
    size_t item_size = sizeof(ros_message->motor1_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t max_serialized_size_key_traveler_msgs__msg__TravelerStatus(
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
  // Field name: state_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toeforce_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toeforce_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toe_pos_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: toe_pos_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor0_pos
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor1_pos
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor0_torque
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: motor1_torque
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = traveler_msgs__msg__TravelerStatus;
    is_plain =
      (
      offsetof(DataType, motor1_torque) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _TravelerStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const traveler_msgs__msg__TravelerStatus * ros_message = static_cast<const traveler_msgs__msg__TravelerStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_traveler_msgs__msg__TravelerStatus(ros_message, cdr);
}

static bool _TravelerStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  traveler_msgs__msg__TravelerStatus * ros_message = static_cast<traveler_msgs__msg__TravelerStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_traveler_msgs__msg__TravelerStatus(cdr, ros_message);
}

static uint32_t _TravelerStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_traveler_msgs__msg__TravelerStatus(
      untyped_ros_message, 0));
}

static size_t _TravelerStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_traveler_msgs__msg__TravelerStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TravelerStatus = {
  "traveler_msgs::msg",
  "TravelerStatus",
  _TravelerStatus__cdr_serialize,
  _TravelerStatus__cdr_deserialize,
  _TravelerStatus__get_serialized_size,
  _TravelerStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _TravelerStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TravelerStatus,
  get_message_typesupport_handle_function,
  &traveler_msgs__msg__TravelerStatus__get_type_hash,
  &traveler_msgs__msg__TravelerStatus__get_type_description,
  &traveler_msgs__msg__TravelerStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, traveler_msgs, msg, TravelerStatus)() {
  return &_TravelerStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
