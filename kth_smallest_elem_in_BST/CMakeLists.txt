cmake_minimum_required(VERSION 3.2)
project(kth_smallest_elem_in_BST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(kth_smallest_elem_in_BST ${SOURCE_FILES})