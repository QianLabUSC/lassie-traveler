// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice
#include "traveler_msgs/msg/detail/traveler_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
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

static bool _TravelerStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TravelerStatus__ros_msg_type * ros_message = static_cast<const _TravelerStatus__ros_msg_type *>(untyped_ros_message);
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

static bool _TravelerStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TravelerStatus__ros_msg_type * ros_message = static_cast<_TravelerStatus__ros_msg_type *>(untyped_ros_message);
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
}

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

  // field.name state_flag
  {
    size_t item_size = sizeof(ros_message->state_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toeforce_x
  {
    size_t item_size = sizeof(ros_message->toeforce_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toeforce_y
  {
    size_t item_size = sizeof(ros_message->toeforce_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toe_pos_x
  {
    size_t item_size = sizeof(ros_message->toe_pos_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toe_pos_y
  {
    size_t item_size = sizeof(ros_message->toe_pos_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor0_pos
  {
    size_t item_size = sizeof(ros_message->motor0_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor1_pos
  {
    size_t item_size = sizeof(ros_message->motor1_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor0_torque
  {
    size_t item_size = sizeof(ros_message->motor0_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor1_torque
  {
    size_t item_size = sizeof(ros_message->motor1_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TravelerStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_traveler_msgs__msg__TravelerStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_traveler_msgs
size_t max_serialized_size_traveler_msgs__msg__TravelerStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: state_flag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: toeforce_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: toeforce_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: toe_pos_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: toe_pos_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: motor0_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: motor1_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: motor0_torque
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: motor1_torque
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _TravelerStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_traveler_msgs__msg__TravelerStatus(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_TravelerStatus = {
  "traveler_msgs::msg",
  "TravelerStatus",
  _TravelerStatus__cdr_serialize,
  _TravelerStatus__cdr_deserialize,
  _TravelerStatus__get_serialized_size,
  _TravelerStatus__max_serialized_size
};

static rosidl_message_type_support_t _TravelerStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TravelerStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, traveler_msgs, msg, TravelerStatus)() {
  return &_TravelerStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
