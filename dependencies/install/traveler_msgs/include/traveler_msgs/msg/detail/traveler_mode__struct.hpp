// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from traveler_msgs:msg/TravelerMode.idl
// generated code does not contain a copyright notice

#ifndef TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_HPP_
#define TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__traveler_msgs__msg__TravelerMode __attribute__((deprecated))
#else
# define DEPRECATED__traveler_msgs__msg__TravelerMode __declspec(deprecated)
#endif

namespace traveler_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TravelerMode_
{
  using Type = TravelerMode_<ContainerAllocator>;

  explicit TravelerMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_flag = false;
      this->traveler_mode = 0;
    }
  }

  explicit TravelerMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_flag = false;
      this->traveler_mode = 0;
    }
  }

  // field types and members
  using _start_flag_type =
    bool;
  _start_flag_type start_flag;
  using _traveler_mode_type =
    int8_t;
  _traveler_mode_type traveler_mode;

  // setters for named parameter idiom
  Type & set__start_flag(
    const bool & _arg)
  {
    this->start_flag = _arg;
    return *this;
  }
  Type & set__traveler_mode(
    const int8_t & _arg)
  {
    this->traveler_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    traveler_msgs::msg::TravelerMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const traveler_msgs::msg::TravelerMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      traveler_msgs::msg::TravelerMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__traveler_msgs__msg__TravelerMode
    std::shared_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__traveler_msgs__msg__TravelerMode
    std::shared_ptr<traveler_msgs::msg::TravelerMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TravelerMode_ & other) const
  {
    if (this->start_flag != other.start_flag) {
      return false;
    }
    if (this->traveler_mode != other.traveler_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const TravelerMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TravelerMode_

// alias to use template instance with default allocator
using TravelerMode =
  traveler_msgs::msg::TravelerMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace traveler_msgs

#endif  // TRAVELER_MSGS__MSG__DETAIL__TRAVELER_MODE__STRUCT_HPP_
