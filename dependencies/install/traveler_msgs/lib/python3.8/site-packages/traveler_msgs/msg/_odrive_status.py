# generated from rosidl_generator_py/resource/_idl.py.em
# with input from traveler_msgs:msg/OdriveStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OdriveStatus(type):
    """Metaclass of message 'OdriveStatus'."""

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
                'traveler_msgs.msg.OdriveStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__odrive_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__odrive_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__odrive_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__odrive_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__odrive_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OdriveStatus(metaclass=Metaclass_OdriveStatus):
    """Message class 'OdriveStatus'."""

    __slots__ = [
        '_can_channel',
        '_axis',
        '_pos_estimate',
        '_vel_estimate',
        '_iq_setpoint',
        '_iq_measured',
    ]

    _fields_and_field_types = {
        'can_channel': 'uint8',
        'axis': 'uint8',
        'pos_estimate': 'float',
        'vel_estimate': 'float',
        'iq_setpoint': 'float',
        'iq_measured': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.can_channel = kwargs.get('can_channel', int())
        self.axis = kwargs.get('axis', int())
        self.pos_estimate = kwargs.get('pos_estimate', float())
        self.vel_estimate = kwargs.get('vel_estimate', float())
        self.iq_setpoint = kwargs.get('iq_setpoint', float())
        self.iq_measured = kwargs.get('iq_measured', float())

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
        if self.pos_estimate != other.pos_estimate:
            return False
        if self.vel_estimate != other.vel_estimate:
            return False
        if self.iq_setpoint != other.iq_setpoint:
            return False
        if self.iq_measured != other.iq_measured:
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
    def pos_estimate(self):
        """Message field 'pos_estimate'."""
        return self._pos_estimate

    @pos_estimate.setter
    def pos_estimate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_estimate' field must be of type 'float'"
        self._pos_estimate = value

    @property
    def vel_estimate(self):
        """Message field 'vel_estimate'."""
        return self._vel_estimate

    @vel_estimate.setter
    def vel_estimate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_estimate' field must be of type 'float'"
        self._vel_estimate = value

    @property
    def iq_setpoint(self):
        """Message field 'iq_setpoint'."""
        return self._iq_setpoint

    @iq_setpoint.setter
    def iq_setpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'iq_setpoint' field must be of type 'float'"
        self._iq_setpoint = value

    @property
    def iq_measured(self):
        """Message field 'iq_measured'."""
        return self._iq_measured

    @iq_measured.setter
    def iq_measured(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'iq_measured' field must be of type 'float'"
        self._iq_measured = value
