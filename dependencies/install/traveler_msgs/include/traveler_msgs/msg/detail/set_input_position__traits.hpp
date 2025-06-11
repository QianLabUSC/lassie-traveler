// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/SetInputPosition.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_

#include "traveler_msgs/msg/detail/set_input_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<traveler_msgs::msg::SetInputPosition>()
{
  return "traveler_msgs::msg::SetInputPosition";
}

template<>
inline const char * name<traveler_msgs::msg::SetInputPosition>()
{
  return "traveler_msgs/msg/SetInputPosition";
}

template<>
struct has_fixed_size<traveler_msgs::msg::SetInputPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::SetInputPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::SetInputPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__TRAITS_HPP_
