cmake_minimum_required(VERSION 3.5)
project(CS2510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "Assignment 4/sphere.cpp" "Assignment 4/shape.h" "Assignment 4/cylinder.cpp" "Assignment 4/rightcircularcone.cpp" "Assignment 4/main.cpp" "Assignment 4/controller.h" "Assignment 4/controller_derive1.cpp" "Assignment 4/controller_derive2.cpp" "Assignment 4/controller_derive3.cpp")
add_executable(CS2510 ${SOURCE_FILES})