cmake_minimum_required(VERSION 3.20)
project(str C)

set(CMAKE_C_STANDARD 11)

add_executable(str main.c
        string/tasks/delete_spaces/delete_spaces.c
        string/tasks/delete_spaces/delete_spaces.h)

add_library(string string/string_.h string/string_.c)

target_link_libraries(str string)