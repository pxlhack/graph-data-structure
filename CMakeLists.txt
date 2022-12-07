cmake_minimum_required(VERSION 3.24)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        main.cpp
        src/graph_vertex.cpp lib/graph_vertex.h
        graph_edge.cpp graph_edge.h)
