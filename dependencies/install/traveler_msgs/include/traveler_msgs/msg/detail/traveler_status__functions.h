// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from traveler_msgs:msg/TravelerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__FUNCTIONS_H_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "traveler_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "traveler_msgs/msg/detail/traveler_status__struct.h"

/// Initialize msg/TravelerStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * traveler_msgs__msg__TravelerStatus
 * )) before or use
 * traveler_msgs__msg__TravelerStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__init(traveler_msgs__msg__TravelerStatus * msg);

/// Finalize msg/TravelerStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
void
traveler_msgs__msg__TravelerStatus__fini(traveler_msgs__msg__TravelerStatus * msg);

/// Create msg/TravelerStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * traveler_msgs__msg__TravelerStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
traveler_msgs__msg__TravelerStatus *
traveler_msgs__msg__TravelerStatus__create();

/// Destroy msg/TravelerStatus message.
/**
 * It calls
 * traveler_msgs__msg__TravelerStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
void
traveler_msgs__msg__TravelerStatus__destroy(traveler_msgs__msg__TravelerStatus * msg);

/// Check for msg/TravelerStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__are_equal(const traveler_msgs__msg__TravelerStatus * lhs, const traveler_msgs__msg__TravelerStatus * rhs);

/// Copy a msg/TravelerStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__copy(
  const traveler_msgs__msg__TravelerStatus * input,
  traveler_msgs__msg__TravelerStatus * output);

/// Initialize array of msg/TravelerStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * traveler_msgs__msg__TravelerStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__Sequence__init(traveler_msgs__msg__TravelerStatus__Sequence * array, size_t size);

/// Finalize array of msg/TravelerStatus messages.
/**
 * It calls
 * traveler_msgs__msg__TravelerStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
void
traveler_msgs__msg__TravelerStatus__Sequence__fini(traveler_msgs__msg__TravelerStatus__Sequence * array);

/// Create array of msg/TravelerStatus messages.
/**
 * It allocates the memory for the array and calls
 * traveler_msgs__msg__TravelerStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
traveler_msgs__msg__TravelerStatus__Sequence *
traveler_msgs__msg__TravelerStatus__Sequence__create(size_t size);

/// Destroy array of msg/TravelerStatus messages.
/**
 * It calls
 * traveler_msgs__msg__TravelerStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
void
traveler_msgs__msg__TravelerStatus__Sequence__destroy(traveler_msgs__msg__TravelerStatus__Sequence * array);

/// Check for msg/TravelerStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__Sequence__are_equal(const traveler_msgs__msg__TravelerStatus__Sequence * lhs, const traveler_msgs__msg__TravelerStatus__Sequence * rhs);

/// Copy an array of msg/TravelerStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_traveler_msgs
bool
traveler_msgs__msg__TravelerStatus__Sequence__copy(
  const traveler_msgs__msg__TravelerStatus__Sequence * input,
  traveler_msgs__msg__TravelerStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_STATUS__FUNCTIONS_H_
