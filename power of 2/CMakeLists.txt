cmake_minimum_required(VERSION 3.2)
project(power_of_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(power_of_2 ${SOURCE_FILES})