##############################
## test_msgs CMakeLists.txt ##
##############################

cmake_minimum_required(VERSION 3.10.2)
project(test_msgs 
        VERSION 0.1.0 )

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Message dependencies
find_package(std_msgs REQUIRED)

# Add message files
rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/DataMessage1.msg"
    "msg/DataMessage2.msg"
    DEPENDENCIES
        "std_msgs"
)

ament_package()
