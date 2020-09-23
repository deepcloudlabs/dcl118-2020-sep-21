cmake_minimum_required(VERSION 3.17)
project(module08_mysql_programming_with_mysql_connector_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(query-example query-example.cpp)
add_executable(insert-example insert-example.cpp)

include_directories(/usr/include/mysql-cppconn-8/jdbc)

target_link_libraries(query-example mysqlcppconn8 mysqlcppconn)
target_link_libraries(insert-example mysqlcppconn8 mysqlcppconn)