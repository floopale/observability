from setuptools import find_packages
from setuptools import setup

setup(
    name='test_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('test_msgs', 'test_msgs.*')),
)
