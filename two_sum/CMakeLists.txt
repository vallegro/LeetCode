cmake_minimum_required(VERSION 3.2)
project(two_sum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(two_sum ${SOURCE_FILES})