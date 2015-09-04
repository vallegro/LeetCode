cmake_minimum_required(VERSION 3.2)
project(excel_sheet_title)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(excel_sheet_title ${SOURCE_FILES})