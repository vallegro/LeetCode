cmake_minimum_required(VERSION 3.2)
project(intersection_two_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(intersection_two_linked_list ${SOURCE_FILES})