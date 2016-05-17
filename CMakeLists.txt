cmake_minimum_required(VERSION 3.5)
project(CS2510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "Assignment 1/vector_seq.cpp")
add_executable(CS2510 ${SOURCE_FILES})