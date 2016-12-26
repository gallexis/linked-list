cmake_minimum_required(VERSION 3.6)
project(linked_lists)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

set(SOURCE_FILES main.c linkedList.c linkedList.h)

add_executable(linked_lists ${SOURCE_FILES})