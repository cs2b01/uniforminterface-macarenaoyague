cmake_minimum_required(VERSION 3.13)
project(Testing)

set(CMAKE_CXX_STANDARD 17)

add_executable(Testing main.cpp forward.h list.h node.h)