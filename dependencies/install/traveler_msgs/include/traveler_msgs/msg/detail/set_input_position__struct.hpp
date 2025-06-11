// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from traveler_msgs:msg/SetInputPosition.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__STRUCT_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__traveler_msgs__msg__SetInputPosition __attribute__((deprecated))
#else
# define DEPRECATED__traveler_msgs__msg__SetInputPosition __declspec(deprecated)
#endif

namespace traveler_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetInputPosition_
{
  using Type = SetInputPosition_<ContainerAllocator>;

  explicit SetInputPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_channel = 0;
      this->axis = 0;
      this->input_position = 0.0f;
      this->vel_ff = 0;
      this->torque_ff = 0;
    }
  }

  explicit SetInputPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->can_channel = 0;
      this->axis = 0;
      this->input_position = 0.0f;
      this->vel_ff = 0;
      this->torque_ff = 0;
    }
  }

  // field types and members
  using _can_channel_type =
    uint8_t;
  _can_channel_type can_channel;
  using _axis_type =
    uint8_t;
  _axis_type axis;
  using _input_position_type =
    float;
  _input_position_type input_position;
  using _vel_ff_type =
    int16_t;
  _vel_ff_type vel_ff;
  using _torque_ff_type =
    int16_t;
  _torque_ff_type torque_ff;

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
  Type & set__input_position(
    const float & _arg)
  {
    this->input_position = _arg;
    return *this;
  }
  Type & set__vel_ff(
    const int16_t & _arg)
  {
    this->vel_ff = _arg;
    return *this;
  }
  Type & set__torque_ff(
    const int16_t & _arg)
  {
    this->torque_ff = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    traveler_msgs::msg::SetInputPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const traveler_msgs::msg::SetInputPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::SetInputPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::SetInputPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__traveler_msgs__msg__SetInputPosition
    std::shared_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__traveler_msgs__msg__SetInputPosition
    std::shared_ptr<traveler_msgs::msg::SetInputPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetInputPosition_ & other) const
  {
    if (this->can_channel != other.can_channel) {
      return false;
    }
    if (this->axis != other.axis) {
      return false;
    }
    if (this->input_position != other.input_position) {
      return false;
    }
    if (this->vel_ff != other.vel_ff) {
      return false;
    }
    if (this->torque_ff != other.torque_ff) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetInputPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetInputPosition_

// alias to use template instance with default allocator
using SetInputPosition =
  traveler_msgs::msg::SetInputPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__SET_INPUT_POSITION__STRUCT_HPP_
