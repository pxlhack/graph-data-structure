cmake_minimum_required(VERSION 3.21.1)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        main.cpp
        lib/vertex.h
        lib/edge.h lib/graph.h lib/graph_form.h lib/list_form.h lib/matrix_form.h lib/graph_menu.h lib/task_2.h lib/task_3.h)
