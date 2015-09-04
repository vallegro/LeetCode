cmake_minimum_required(VERSION 3.2)
project(multiply_strings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(multiply_strings ${SOURCE_FILES})