cmake_minimum_required(VERSION 3.4)
project(c_misc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=gnu89")

set(SOURCE_FILES main.c lib.c lib.h)

#add_executable(c_misc ${SOURCE_FILES})
add_executable(test2 test2/main.c)
