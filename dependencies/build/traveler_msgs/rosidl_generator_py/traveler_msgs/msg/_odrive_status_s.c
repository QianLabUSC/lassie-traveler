// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from traveler_msgs:msg/OdriveStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "traveler_msgs/msg/detail/odrive_status__struct.h"
#include "traveler_msgs/msg/detail/odrive_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool traveler_msgs__msg__odrive_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("traveler_msgs.msg._odrive_status.OdriveStatus", full_classname_dest, 45) == 0);
  }
  traveler_msgs__msg__OdriveStatus * ros_message = _ros_message;
  {  // can_channel
    PyObject * field = PyObject_GetAttrString(_pymsg, "can_channel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->can_channel = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // axis
    PyObject * field = PyObject_GetAttrString(_pymsg, "axis");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->axis = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pos_estimate
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_estimate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_estimate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_estimate
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_estimate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_estimate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // iq_setpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "iq_setpoint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->iq_setpoint = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // iq_measured
    PyObject * field = PyObject_GetAttrString(_pymsg, "iq_measured");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->iq_measured = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * traveler_msgs__msg__odrive_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OdriveStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("traveler_msgs.msg._odrive_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OdriveStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  traveler_msgs__msg__OdriveStatus * ros_message = (traveler_msgs__msg__OdriveStatus *)raw_ros_message;
  {  // can_channel
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->can_channel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "can_channel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // axis
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->axis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "axis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_estimate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_estimate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_estimate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_estimate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_estimate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_estimate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // iq_setpoint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->iq_setpoint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "iq_setpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // iq_measured
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->iq_measured);
    {
      int rc = PyObject_SetAttrString(_pymessage, "iq_measured", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
