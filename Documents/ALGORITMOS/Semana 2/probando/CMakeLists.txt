cmake_minimum_required(VERSION 3.15)
project(probando)

set(CMAKE_CXX_STANDARD 14)

add_executable(probando
        main.cpp
        stack.h
        queue.h
        node.h
        forward.h
        list.h
        linked.h
        iterators/bidirectional_iterator.h
        iterators/forward_iterator.h
        )