cmake_minimum_required(VERSION 3.2)
project(serch_matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(serch_matrix ${SOURCE_FILES})