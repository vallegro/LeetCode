cmake_minimum_required(VERSION 3.2)
project(tailing_zero)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(tailing_zero ${SOURCE_FILES})