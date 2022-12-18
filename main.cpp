#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"

#define intVertex Vertex<int, int>
#define intEdge Edge<int, int, int>
#define intGraph Graph<intVertex, intEdge>

int main() {

    intGraph graph(10);
//    cout << graph.isDense() << endl;


    return 0;
}
