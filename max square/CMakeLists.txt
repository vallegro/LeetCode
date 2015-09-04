cmake_minimum_required(VERSION 3.2)
project(max_square)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(max_square ${SOURCE_FILES})