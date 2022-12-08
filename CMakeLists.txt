cmake_minimum_required(VERSION 3.24)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        main.cpp
        src/graph_vertex.cpp lib/graph_vertex.h
        src/graph_edge.cpp lib/graph_edge.h src/graph.cpp lib/graph.h src/graph_form.cpp lib/graph_form.h src/l_graph_form.cpp lib/l_graph_form.h src/m_graph_form.cpp lib/m_graph_form.h)
