cmake_minimum_required(VERSION 3.4)

project(c_misc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=gnu99")

set(SOURCE_FILES main.c lib.c lib.h)

set(SOURCE2 inline/main.c inline/target.c)

add_executable(test3 ${SOURCE2})
