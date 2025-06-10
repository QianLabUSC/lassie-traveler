from setuptools import find_packages
from setuptools import setup

setup(
    name='traveler_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('traveler_msgs', 'traveler_msgs.*')),
)
