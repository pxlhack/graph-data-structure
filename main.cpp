#include <iostream>
#include "lib/graph.h"
#include "lib/graph_vertex.h"
#include "lib/graph_edge.h"

int main() {
    Graph<Vertex<int, int>, Edge<int, int, int>> graph(10);
//    cout << graph.isDense() << endl;


    return 0;
}
