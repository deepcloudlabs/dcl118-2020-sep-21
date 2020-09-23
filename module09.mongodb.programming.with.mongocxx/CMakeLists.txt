cmake_minimum_required(VERSION 3.17)
project(module09_mongodb_programming_with_mongocxx)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/local/include/bsoncxx/v_noabi /usr/local/include/mongocxx/v_noabi)
link_directories(/usr/local/lib)

add_executable(test-connection test-connection.cpp)
add_executable(query-collection query-collection.cpp)
add_executable(create-document create-document.cpp)

target_link_libraries(test-connection mongocxx bsoncxx)
target_link_libraries(query-collection mongocxx bsoncxx)
target_link_libraries(create-document mongocxx bsoncxx)