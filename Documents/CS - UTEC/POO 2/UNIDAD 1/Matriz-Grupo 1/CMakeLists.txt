cmake_minimum_required(VERSION 3.13)
project(intentos)

set(CMAKE_CXX_STANDARD 14)

add_executable(intentos main.cpp Matriz.cpp Matriz.h OperacionesDeMatrices.h SobrecargaDeOperadores.h)