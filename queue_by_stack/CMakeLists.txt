cmake_minimum_required(VERSION 3.2)
project(que_by_stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(que_by_stack ${SOURCE_FILES})