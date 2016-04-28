cmake_minimum_required(VERSION 3.5)
project(testme)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES testme.c randomstring.c)
add_executable(testme ${SOURCE_FILES})