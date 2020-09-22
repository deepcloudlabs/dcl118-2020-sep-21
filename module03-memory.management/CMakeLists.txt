cmake_minimum_required(VERSION 3.17)
project(module03_memory_management)

set(CMAKE_CXX_STANDARD 17)

add_executable(module03_memory_management main.cpp)
add_executable(memory_location memory_location.cpp)
add_executable(new-with-exception new-with-exception.cpp)
add_executable(new-without-exception new-without-exception.cpp)
add_executable(memory_alignment memory_alignment.cpp)
add_executable(memory_alignment_alternative memory_alignment_alternative.cpp)
add_executable(study_shared_ptr study_shared_ptr.cpp)
add_executable(study_weak_ptr study_weak_ptr.cpp)