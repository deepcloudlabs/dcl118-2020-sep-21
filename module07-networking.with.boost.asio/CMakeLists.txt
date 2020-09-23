cmake_minimum_required(VERSION 3.17)
project(module07_networking_with_boost_asio)

set(CMAKE_CXX_STANDARD 14)

add_executable(lottery-server lottery-server.cpp)
add_executable(lottery-client lottery-client.cpp)

target_link_libraries(lottery-server pthread boost_system)
target_link_libraries(lottery-client pthread boost_system)