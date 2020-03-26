cmake_minimum_required(VERSION 3.13)
project(MATRIZ)

set(CMAKE_CXX_STANDARD 14)

add_executable(MATRIZ main.cpp Matriz_Test.cpp OperacionesDeMatrices.h SobrecargaDeOperadores.h Matriz.cpp Matriz.h)