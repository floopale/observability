###################################
## test_pub_node CMakeLists.txt  ##
###################################

cmake_minimum_required(VERSION 3.10.2)
project(test_pub_node 
        VERSION 0.1.0 
        LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add main file
set(SRC_FILES
    src/main.cpp
)

# Add Source files
set(SRC_FILES
    ${SRC_FILES}
    src/TestPubNode.cpp
)

add_executable(${PROJECT_NAME} 
    ${SRC_FILES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    PRIVATE
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Target options/features
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Set up public/private dependencies that are non-ROS
find_package(Boost 1.65 REQUIRED)
find_package(Boost 1.65 COMPONENTS system filesystem REQUIRED)

# ROS dependencies
find_package(ament_cmake REQUIRED)
find_package(observability_library REQUIRED)
find_package(test_msgs REQUIRED)
find_package(rclcpp REQUIRED)
#find_package(vehicle_interface_msgs REQUIRED)

target_link_libraries(${PROJECT_NAME}
                      ${Boost_LIBRARIES})

ament_target_dependencies(${PROJECT_NAME}
#    common_library
#    joystick_msgs
    test_msgs
    observability_library
    rclcpp
#    vehicle_interface_msgs
)

install(TARGETS 
    ${PROJECT_NAME} 
    DESTINATION lib/${PROJECT_NAME} 
)

#install(DIRECTORY
#  config
#  DESTINATION share/${PROJECT_NAME}
#)
#
#install(DIRECTORY
#  launch
#  DESTINATION share/${PROJECT_NAME}
#)

ament_package()
