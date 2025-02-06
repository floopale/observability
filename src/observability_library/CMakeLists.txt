#############################################################################
## Observability library to provide base observability about components    ##
#############################################################################

cmake_minimum_required(VERSION 3.10.2)
project(observability_library VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Add ros source files
set(SRC_FILES
    src/ros/InstrNode.cpp
)

# Add helper source files
set(SRC_FILES
    ${SRC_FILES}
    src/helpers/ProcStatReader.cpp
    src/helpers/SubscriberStats.cpp
    src/helpers/TimerStats.cpp
    src/helpers/utilities.cpp
)

include_directories(include)

add_library(${PROJECT_NAME}
    ${SRC_FILES}
)

# Setup public and private includes
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Target options/features
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Set up public/private dependencies that are non-ROS
find_package(Boost 1.65 REQUIRED)
find_package(Eigen3 3.3.7 REQUIRED)

#target_link_libraries(${PROJECT_NAME}
#    PUBLIC
#        Boost::boost
#        Eigen3::Eigen
#    PRIVATE
#)
#option( BUILD_SHARED_LIBS OFF)
  
# Find ament_cmake dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)

ament_target_dependencies(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${Eigen_LIBRARIES}
    std_msgs
    rclcpp    
)

# Export and install library within ament framework
ament_export_targets(${PROJECT_NAME} HAS_LIBRARY_TARGET)
#ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories(include)
ament_export_dependencies(
    Boost
    Eigen3
#    health_msgs
    rclcpp
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib
    INCLUDES DESTINATION include
)

install(DIRECTORY include/
        DESTINATION include
)

ament_package()
