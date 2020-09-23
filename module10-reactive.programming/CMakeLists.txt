cmake_minimum_required(VERSION 3.17)
project(module10_reactive_programming)

set(CMAKE_CXX_STANDARD 14)
include_directories("/home/guru/range-v3/include")

add_executable(ranges0 ranges0.cpp)
add_executable(ranges1 ranges1.cpp city.cpp country.cpp world-util.cpp)
add_executable(ranges2 ranges2.cpp city.cpp country.cpp world-util.cpp)
add_executable(ranges3 ranges3.cpp city.cpp country.cpp world-util.cpp)
add_executable(rxcpp-exercises rxcpp-exercises.cpp)

target_include_directories(ranges0 PUBLIC "/home/guru/range-v3/include")
target_include_directories(ranges1 PUBLIC "/home/guru/range-v3/include")
target_include_directories(ranges2 PUBLIC "/home/guru/range-v3/include")
target_include_directories(ranges3 PUBLIC "/home/guru/range-v3/include")