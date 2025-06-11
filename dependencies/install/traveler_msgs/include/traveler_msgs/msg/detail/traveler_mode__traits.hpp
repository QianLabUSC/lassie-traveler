// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_

#include "traveler_msgs/msg/detail/traveler_mode__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<traveler_msgs::msg::TravelerMode>()
{
  return "traveler_msgs::msg::TravelerMode";
}

template<>
inline const char * name<traveler_msgs::msg::TravelerMode>()
{
  return "traveler_msgs/msg/TravelerMode";
}

template<>
struct has_fixed_size<traveler_msgs::msg::TravelerMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<traveler_msgs::msg::TravelerMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<traveler_msgs::msg::TravelerMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__TRAITS_HPP_
