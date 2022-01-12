cmake_minimum_required(VERSION 3.0.2)

project(main)

# get all the src files 
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE SRC_MAILBOX CONFIGURE_DEPENDS src/mailboxes/*.cpp)
file(GLOB_RECURSE SRC_SERIAL CONFIGURE_DEPENDS src/serial/*.cpp)

# fail-safe serial lib getter and ROS packages import
find_package(serial) # this line is needed for the work-around to find the MANUALLY installed serial library
find_package(catkin REQUIRED COMPONENTS 
    serial 
    roscpp
    rosconsole
)

# include all the catkin_includes directories
include_directories(${catkin_INCLUDE_DIRS})

# init all the executables
add_executable(main_node main_writer.cpp ${SRC_FILES} ${SRC_MAILBOX} ${SRC_SERIAL})
add_executable(main_reader main_reader.cpp ${SRC_FILES} ${SRC_MAILBOX} ${SRC_SERIAL})

# add all the include directories
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions) # need to look for a proper way to include all the things
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/mailboxes) # need to look for a proper way to include all the things
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/serial) # need to look for a proper way to include all the things
target_include_directories(main_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/outputs) # need to look for a proper way to include all the things

# Temporary - reader portion
target_include_directories(main_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(main_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions) # need to look for a proper way to include all the things
target_include_directories(main_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/mailboxes) # need to look for a proper way to include all the things
target_include_directories(main_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/serial) # need to look for a proper way to include all the things
target_include_directories(main_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/outputs) # need to look for a proper way to include all the things

# link the catkin_libraries to the project executables
target_link_libraries(main_node ${catkin_LIBRARIES})
target_link_libraries(main_reader ${catkin_LIBRARIES})