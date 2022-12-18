cmake_minimum_required(VERSION 3.24)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        main.cpp
        lib/graph_vertex.h
        lib/graph_edge.h lib/graph.h lib/graph_form.h lib/l_graph_form.h lib/m_graph_form.h)
