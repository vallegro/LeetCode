cmake_minimum_required(VERSION 3.2)
project(maxprodcut_subarray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(maxprodcut_subarray ${SOURCE_FILES})