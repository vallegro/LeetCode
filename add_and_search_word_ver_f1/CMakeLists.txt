cmake_minimum_required(VERSION 3.2)
project(Add_and_Search_Word)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Add_and_Search_Word ${SOURCE_FILES})