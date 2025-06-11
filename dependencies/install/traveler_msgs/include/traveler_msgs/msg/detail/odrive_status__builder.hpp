// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__BUILDER_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__BUILDER_HPP_

#include "traveler_msgs/msg/detail/odrive_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace traveler_msgs
{

namespace msg
{

namespace builder
{

class Init_OdriveStatus_iq_measured
{
public:
  explicit Init_OdriveStatus_iq_measured(::traveler_msgs::msg::OdriveStatus & msg)
  : msg_(msg)
  {}
  ::traveler_msgs::msg::OdriveStatus iq_measured(::traveler_msgs::msg::OdriveStatus::_iq_measured_type arg)
  {
    msg_.iq_measured = std::move(arg);
    return std::move(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

class Init_OdriveStatus_iq_setpoint
{
public:
  explicit Init_OdriveStatus_iq_setpoint(::traveler_msgs::msg::OdriveStatus & msg)
  : msg_(msg)
  {}
  Init_OdriveStatus_iq_measured iq_setpoint(::traveler_msgs::msg::OdriveStatus::_iq_setpoint_type arg)
  {
    msg_.iq_setpoint = std::move(arg);
    return Init_OdriveStatus_iq_measured(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

class Init_OdriveStatus_vel_estimate
{
public:
  explicit Init_OdriveStatus_vel_estimate(::traveler_msgs::msg::OdriveStatus & msg)
  : msg_(msg)
  {}
  Init_OdriveStatus_iq_setpoint vel_estimate(::traveler_msgs::msg::OdriveStatus::_vel_estimate_type arg)
  {
    msg_.vel_estimate = std::move(arg);
    return Init_OdriveStatus_iq_setpoint(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

class Init_OdriveStatus_pos_estimate
{
public:
  explicit Init_OdriveStatus_pos_estimate(::traveler_msgs::msg::OdriveStatus & msg)
  : msg_(msg)
  {}
  Init_OdriveStatus_vel_estimate pos_estimate(::traveler_msgs::msg::OdriveStatus::_pos_estimate_type arg)
  {
    msg_.pos_estimate = std::move(arg);
    return Init_OdriveStatus_vel_estimate(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

class Init_OdriveStatus_axis
{
public:
  explicit Init_OdriveStatus_axis(::traveler_msgs::msg::OdriveStatus & msg)
  : msg_(msg)
  {}
  Init_OdriveStatus_pos_estimate axis(::traveler_msgs::msg::OdriveStatus::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return Init_OdriveStatus_pos_estimate(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

class Init_OdriveStatus_can_channel
{
public:
  Init_OdriveStatus_can_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OdriveStatus_axis can_channel(::traveler_msgs::msg::OdriveStatus::_can_channel_type arg)
  {
    msg_.can_channel = std::move(arg);
    return Init_OdriveStatus_axis(msg_);
  }

private:
  ::traveler_msgs::msg::OdriveStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::traveler_msgs::msg::OdriveStatus>()
{
  return traveler_msgs::msg::builder::Init_OdriveStatus_can_channel();
}

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__BUILDER_HPP_
