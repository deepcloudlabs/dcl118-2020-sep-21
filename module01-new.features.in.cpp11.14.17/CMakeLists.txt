cmake_minimum_required(VERSION 3.17)
project(new_features)

set(CMAKE_CXX_STANDARD 17)

add_executable(new_features main.cpp uniform-initialization.cpp study-explicit.cpp study_auto.cpp study_decltype.cpp study_constexpr.cpp study-for-each-loop.cpp study_forwarding_constructor.cpp study_rvalue.cpp study_move_constructor_and_move_semantics.cpp)
add_executable(study_decltype study_decltype.cpp)
add_executable(study_constexpr study_constexpr.cpp)
add_executable(study-for-each-loop study-for-each-loop.cpp)
add_executable(study_forwarding_constructor study_forwarding_constructor.cpp)
add_executable(study_rvalue study_rvalue.cpp)
add_executable(study_move_constructor_and_move_semantics study_move_constructor_and_move_semantics.cpp)