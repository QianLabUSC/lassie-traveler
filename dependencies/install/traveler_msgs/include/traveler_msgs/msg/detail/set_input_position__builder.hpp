// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from traveler_msgs:msg/SetInputPosition.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__BUILDER_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__BUILDER_HPP_

#include "traveler_msgs/msg/detail/set_input_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace traveler_msgs
{

namespace msg
{

namespace builder
{

class Init_SetInputPosition_torque_ff
{
public:
  explicit Init_SetInputPosition_torque_ff(::traveler_msgs::msg::SetInputPosition & msg)
  : msg_(msg)
  {}
  ::traveler_msgs::msg::SetInputPosition torque_ff(::traveler_msgs::msg::SetInputPosition::_torque_ff_type arg)
  {
    msg_.torque_ff = std::move(arg);
    return std::move(msg_);
  }

private:
  ::traveler_msgs::msg::SetInputPosition msg_;
};

class Init_SetInputPosition_vel_ff
{
public:
  explicit Init_SetInputPosition_vel_ff(::traveler_msgs::msg::SetInputPosition & msg)
  : msg_(msg)
  {}
  Init_SetInputPosition_torque_ff vel_ff(::traveler_msgs::msg::SetInputPosition::_vel_ff_type arg)
  {
    msg_.vel_ff = std::move(arg);
    return Init_SetInputPosition_torque_ff(msg_);
  }

private:
  ::traveler_msgs::msg::SetInputPosition msg_;
};

class Init_SetInputPosition_input_position
{
public:
  explicit Init_SetInputPosition_input_position(::traveler_msgs::msg::SetInputPosition & msg)
  : msg_(msg)
  {}
  Init_SetInputPosition_vel_ff input_position(::traveler_msgs::msg::SetInputPosition::_input_position_type arg)
  {
    msg_.input_position = std::move(arg);
    return Init_SetInputPosition_vel_ff(msg_);
  }

private:
  ::traveler_msgs::msg::SetInputPosition msg_;
};

class Init_SetInputPosition_axis
{
public:
  explicit Init_SetInputPosition_axis(::traveler_msgs::msg::SetInputPosition & msg)
  : msg_(msg)
  {}
  Init_SetInputPosition_input_position axis(::traveler_msgs::msg::SetInputPosition::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return Init_SetInputPosition_input_position(msg_);
  }

private:
  ::traveler_msgs::msg::SetInputPosition msg_;
};

class Init_SetInputPosition_can_channel
{
public:
  Init_SetInputPosition_can_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetInputPosition_axis can_channel(::traveler_msgs::msg::SetInputPosition::_can_channel_type arg)
  {
    msg_.can_channel = std::move(arg);
    return Init_SetInputPosition_axis(msg_);
  }

private:
  ::traveler_msgs::msg::SetInputPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::traveler_msgs::msg::SetInputPosition>()
{
  return traveler_msgs::msg::builder::Init_SetInputPosition_can_channel();
}

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__BUILDER_HPP_
