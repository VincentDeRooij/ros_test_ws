cmake_minimum_required(VERSION 3.0.2)

project(main)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

find_package(serial) # this line is needed for the work-around to find the MANUALLY installed serial library
find_package(catkin REQUIRED COMPONENTS serial)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(main_node main.cpp ${SRC_FILES})

target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions) # need to look for a proper way to include all the things

target_link_libraries(main_node ${catkin_LIBRARIES})