cmake_minimum_required(VERSION 3.4)
project(c_misc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c lib.c lib.h)

#add_executable(c_misc ${SOURCE_FILES})
add_executable(test2 test2/main.c)
