# generated from rosidl_generator_py/resource/_idl.py.em
# with input from traveler_msgs:msg/TravelerStatus.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TravelerStatus(type):
    """Metaclass of message 'TravelerStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('traveler_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'traveler_msgs.msg.TravelerStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__traveler_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__traveler_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__traveler_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__traveler_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__traveler_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TravelerStatus(metaclass=Metaclass_TravelerStatus):
    """Message class 'TravelerStatus'."""

    __slots__ = [
        '_state_flag',
        '_time',
        '_toeforce_x',
        '_toeforce_y',
        '_toe_pos_x',
        '_toe_pos_y',
        '_motor0_pos',
        '_motor1_pos',
        '_motor0_torque',
        '_motor1_torque',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'state_flag': 'uint8',
        'time': 'float',
        'toeforce_x': 'float',
        'toeforce_y': 'float',
        'toe_pos_x': 'float',
        'toe_pos_y': 'float',
        'motor0_pos': 'float',
        'motor1_pos': 'float',
        'motor0_torque': 'float',
        'motor1_torque': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state_flag = kwargs.get('state_flag', int())
        self.time = kwargs.get('time', float())
        self.toeforce_x = kwargs.get('toeforce_x', float())
        self.toeforce_y = kwargs.get('toeforce_y', float())
        self.toe_pos_x = kwargs.get('toe_pos_x', float())
        self.toe_pos_y = kwargs.get('toe_pos_y', float())
        self.motor0_pos = kwargs.get('motor0_pos', float())
        self.motor1_pos = kwargs.get('motor1_pos', float())
        self.motor0_torque = kwargs.get('motor0_torque', float())
        self.motor1_torque = kwargs.get('motor1_torque', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.state_flag != other.state_flag:
            return False
        if self.time != other.time:
            return False
        if self.toeforce_x != other.toeforce_x:
            return False
        if self.toeforce_y != other.toeforce_y:
            return False
        if self.toe_pos_x != other.toe_pos_x:
            return False
        if self.toe_pos_y != other.toe_pos_y:
            return False
        if self.motor0_pos != other.motor0_pos:
            return False
        if self.motor1_pos != other.motor1_pos:
            return False
        if self.motor0_torque != other.motor0_torque:
            return False
        if self.motor1_torque != other.motor1_torque:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def state_flag(self):
        """Message field 'state_flag'."""
        return self._state_flag

    @state_flag.setter
    def state_flag(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'state_flag' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state_flag' field must be an unsigned integer in [0, 255]"
        self._state_flag = value

    @builtins.property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'time' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'time' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._time = value

    @builtins.property
    def toeforce_x(self):
        """Message field 'toeforce_x'."""
        return self._toeforce_x

    @toeforce_x.setter
    def toeforce_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'toeforce_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'toeforce_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._toeforce_x = value

    @builtins.property
    def toeforce_y(self):
        """Message field 'toeforce_y'."""
        return self._toeforce_y

    @toeforce_y.setter
    def toeforce_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'toeforce_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'toeforce_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._toeforce_y = value

    @builtins.property
    def toe_pos_x(self):
        """Message field 'toe_pos_x'."""
        return self._toe_pos_x

    @toe_pos_x.setter
    def toe_pos_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'toe_pos_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'toe_pos_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._toe_pos_x = value

    @builtins.property
    def toe_pos_y(self):
        """Message field 'toe_pos_y'."""
        return self._toe_pos_y

    @toe_pos_y.setter
    def toe_pos_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'toe_pos_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'toe_pos_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._toe_pos_y = value

    @builtins.property
    def motor0_pos(self):
        """Message field 'motor0_pos'."""
        return self._motor0_pos

    @motor0_pos.setter
    def motor0_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor0_pos' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor0_pos' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor0_pos = value

    @builtins.property
    def motor1_pos(self):
        """Message field 'motor1_pos'."""
        return self._motor1_pos

    @motor1_pos.setter
    def motor1_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor1_pos' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor1_pos' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor1_pos = value

    @builtins.property
    def motor0_torque(self):
        """Message field 'motor0_torque'."""
        return self._motor0_torque

    @motor0_torque.setter
    def motor0_torque(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor0_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor0_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor0_torque = value

    @builtins.property
    def motor1_torque(self):
        """Message field 'motor1_torque'."""
        return self._motor1_torque

    @motor1_torque.setter
    def motor1_torque(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor1_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor1_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor1_torque = value
