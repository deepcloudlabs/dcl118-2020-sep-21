cmake_minimum_required(VERSION 3.17)
project(module02_thread_programming_in_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(thread_programming thread-programming.cpp)
add_executable(study_race_condition study_race_condition.cpp exception-free-new.cpp memory-locations.cpp)
add_executable(exception-free-new exception-free-new.cpp)
add_executable(exceptional-new exceptional-new.cpp)
add_executable(memory-alignment memory-alignment.cpp)
add_executable(memory-locations memory-locations.cpp)
add_executable(number_of_cores number_of_cores.cpp)

target_link_libraries(thread_programming pthread)
target_link_libraries(study_race_condition pthread)
