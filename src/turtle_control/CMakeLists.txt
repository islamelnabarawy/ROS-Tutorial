cmake_minimum_required(VERSION 2.8.3)
project(turtle_control)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	geometry_msgs
	turtlesim
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES turtle_control
    CATKIN_DEPENDS roscpp geometry_msgs turtlesim
    DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
    ${catkin_INCLUDE_DIRS}
    include/turtle_control
)

add_executable(
    turtle_control_node 
    src/turtle_control/turtle_control.cpp
    src/turtle_control/turtle_control_node.cpp
)

add_dependencies(
    turtle_control_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(
    turtle_control_node
    ${catkin_LIBRARIES}
)

