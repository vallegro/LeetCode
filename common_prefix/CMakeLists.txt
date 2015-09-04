cmake_minimum_required(VERSION 3.2)
project(common_prefix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(common_prefix ${SOURCE_FILES})