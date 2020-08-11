cmake_minimum_required(VERSION 3.15)
project(Automata)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Automata
        Alfabeto.cpp
        Alfabeto.h
        Automata.cpp
        Automata.h
        Estado.cpp
        Estado.h
        main.cpp)
