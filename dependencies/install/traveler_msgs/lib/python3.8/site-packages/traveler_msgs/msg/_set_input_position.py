# generated from rosidl_generator_py/resource/_idl.py.em
# with input from traveler_msgs:msg/SetInputPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetInputPosition(type):
    """Metaclass of message 'SetInputPosition'."""

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
                'traveler_msgs.msg.SetInputPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__set_input_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__set_input_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__set_input_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__set_input_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__set_input_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetInputPosition(metaclass=Metaclass_SetInputPosition):
    """Message class 'SetInputPosition'."""

    __slots__ = [
        '_can_channel',
        '_axis',
        '_input_position',
        '_vel_ff',
        '_torque_ff',
    ]

    _fields_and_field_types = {
        'can_channel': 'uint8',
        'axis': 'uint8',
        'input_position': 'float',
        'vel_ff': 'int16',
        'torque_ff': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.can_channel = kwargs.get('can_channel', int())
        self.axis = kwargs.get('axis', int())
        self.input_position = kwargs.get('input_position', float())
        self.vel_ff = kwargs.get('vel_ff', int())
        self.torque_ff = kwargs.get('torque_ff', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.can_channel != other.can_channel:
            return False
        if self.axis != other.axis:
            return False
        if self.input_position != other.input_position:
            return False
        if self.vel_ff != other.vel_ff:
            return False
        if self.torque_ff != other.torque_ff:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def can_channel(self):
        """Message field 'can_channel'."""
        return self._can_channel

    @can_channel.setter
    def can_channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'can_channel' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'can_channel' field must be an unsigned integer in [0, 255]"
        self._can_channel = value

    @property
    def axis(self):
        """Message field 'axis'."""
        return self._axis

    @axis.setter
    def axis(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'axis' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'axis' field must be an unsigned integer in [0, 255]"
        self._axis = value

    @property
    def input_position(self):
        """Message field 'input_position'."""
        return self._input_position

    @input_position.setter
    def input_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'input_position' field must be of type 'float'"
        self._input_position = value

    @property
    def vel_ff(self):
        """Message field 'vel_ff'."""
        return self._vel_ff

    @vel_ff.setter
    def vel_ff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_ff' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'vel_ff' field must be an integer in [-32768, 32767]"
        self._vel_ff = value

    @property
    def torque_ff(self):
        """Message field 'torque_ff'."""
        return self._torque_ff

    @torque_ff.setter
    def torque_ff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'torque_ff' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'torque_ff' field must be an integer in [-32768, 32767]"
        self._torque_ff = value
