cmake_minimum_required(VERSION 3.26)
project(AutonomousVehicle)

set(CMAKE_CXX_STANDARD 14)

add_executable(AutonomousVehicle
        AVPCL.cpp
        main.cpp)

find_package(PCL 1.8 REQUIRED COMPONENTS io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
target_link_libraries(AutonomousVehicle ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})