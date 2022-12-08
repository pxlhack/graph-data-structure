#include <iostream>
#include "lib/graph.h"
#include "lib/graph_vertex.h"
#include "lib/graph_edge.h"

int main() {
    Graph<GraphVertex<int, int>, GraphEdge<int, int, int>> graph;
    cout << graph.isDense() << endl;
    return 0;
}
