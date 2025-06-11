// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__traveler_msgs__msg__OdriveStatus __attribute__((deprecated))
#else
# define DEPRECATED__traveler_msgs__msg__OdriveStatus __declspec(deprecated)
#endif

namespace traveler_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OdriveStatus_
{
  using Type = OdriveStatus_<ContainerAllocator>;

  explicit OdriveStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_channel = 0;
      this->axis = 0;
      this->pos_estimate = 0.0f;
      this->vel_estimate = 0.0f;
      this->iq_setpoint = 0.0f;
      this->iq_measured = 0.0f;
    }
  }

  explicit OdriveStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_channel = 0;
      this->axis = 0;
      this->pos_estimate = 0.0f;
      this->vel_estimate = 0.0f;
      this->iq_setpoint = 0.0f;
      this->iq_measured = 0.0f;
    }
  }

  // field types and members
  using _can_channel_type =
    uint8_t;
  _can_channel_type can_channel;
  using _axis_type =
    uint8_t;
  _axis_type axis;
  using _pos_estimate_type =
    float;
  _pos_estimate_type pos_estimate;
  using _vel_estimate_type =
    float;
  _vel_estimate_type vel_estimate;
  using _iq_setpoint_type =
    float;
  _iq_setpoint_type iq_setpoint;
  using _iq_measured_type =
    float;
  _iq_measured_type iq_measured;

  // setters for named parameter idiom
  Type & set__can_channel(
    const uint8_t & _arg)
  {
    this->can_channel = _arg;
    return *this;
  }
  Type & set__axis(
    const uint8_t & _arg)
  {
    this->axis = _arg;
    return *this;
  }
  Type & set__pos_estimate(
    const float & _arg)
  {
    this->pos_estimate = _arg;
    return *this;
  }
  Type & set__vel_estimate(
    const float & _arg)
  {
    this->vel_estimate = _arg;
    return *this;
  }
  Type & set__iq_setpoint(
    const float & _arg)
  {
    this->iq_setpoint = _arg;
    return *this;
  }
  Type & set__iq_measured(
    const float & _arg)
  {
    this->iq_measured = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    traveler_msgs::msg::OdriveStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const traveler_msgs::msg::OdriveStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::OdriveStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::OdriveStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__traveler_msgs__msg__OdriveStatus
    std::shared_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__traveler_msgs__msg__OdriveStatus
    std::shared_ptr<traveler_msgs::msg::OdriveStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OdriveStatus_ & other) const
  {
    if (this->can_channel != other.can_channel) {
      return false;
    }
    if (this->axis != other.axis) {
      return false;
    }
    if (this->pos_estimate != other.pos_estimate) {
      return false;
    }
    if (this->vel_estimate != other.vel_estimate) {
      return false;
    }
    if (this->iq_setpoint != other.iq_setpoint) {
      return false;
    }
    if (this->iq_measured != other.iq_measured) {
      return false;
    }
    return true;
  }
  bool operator!=(const OdriveStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OdriveStatus_

// alias to use template instance with default allocator
using OdriveStatus =
  traveler_msgs::msg::OdriveStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__ODRIVE_STATUS__STRUCT_HPP_
