// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from traveler_msgs:msg/TravelerStatus.idl
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
#include "traveler_msgs/msg/detail/traveler_status__struct.h"
#include "traveler_msgs/msg/detail/traveler_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool traveler_msgs__msg__traveler_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("traveler_msgs.msg._traveler_status.TravelerStatus", full_classname_dest, 49) == 0);
  }
  traveler_msgs__msg__TravelerStatus * ros_message = _ros_message;
  {  // state_flag
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_flag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_flag = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // time
    PyObject * field = PyObject_GetAttrString(_pymsg, "time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->time = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // toeforce_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "toeforce_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->toeforce_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // toeforce_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "toeforce_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->toeforce_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // toe_pos_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "toe_pos_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->toe_pos_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // toe_pos_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "toe_pos_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->toe_pos_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor0_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor0_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor0_pos = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor1_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor1_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor1_pos = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor0_torque
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor0_torque");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor0_torque = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor1_torque
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor1_torque");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor1_torque = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * traveler_msgs__msg__traveler_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TravelerStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("traveler_msgs.msg._traveler_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TravelerStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  traveler_msgs__msg__TravelerStatus * ros_message = (traveler_msgs__msg__TravelerStatus *)raw_ros_message;
  {  // state_flag
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state_flag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_flag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toeforce_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->toeforce_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toeforce_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toeforce_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->toeforce_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toeforce_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toe_pos_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->toe_pos_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toe_pos_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toe_pos_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->toe_pos_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toe_pos_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor0_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor0_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor0_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor1_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor1_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor1_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor0_torque
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor0_torque);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor0_torque", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor1_torque
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor1_torque);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor1_torque", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
