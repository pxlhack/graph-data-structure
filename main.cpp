#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"
#include "lib/graph_menu.h"


//todo menu
//todo vIterator
//todo eIterator
//todo Iterator
// todo task2
// todo task3
//todo fix toList toMatrix
int main() {
    /*vector<Vertex<int, int> *> v;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(6, 12, true, true);
    cout << graph1 << endl;

    vector<Edge<Vertex<int, int>, int, int> *> eV = graph1.getEdgesVector();
    for (Edge<Vertex<int, int>, int, int> *e: eV) {
        cout << e->getV1()->getIndex() << " " << e->getV2()->getIndex() << endl;
    }
    cout << "\n";

    cout << "Vertices:\n";
    auto it = graph1.vBegin();
    while (it != graph1.vEnd()) {
        Vertex<int, int> vertex = *it;
        cout << vertex << endl;

        ++it;
    }

    cout << "Edges:\n";
    auto it2 = graph1.eBegin();
    while (it2 != graph1.eEnd()) {
        Edge<Vertex<int, int>, int, int> edge = *it2;
        cout << edge << endl;
        ++it2;
    }

    cout << "Outdoing edges:\n";
    auto it3 = graph1.oeBegin(graph1.get(2));
    while (it3 != graph1.oeEnd(graph1.get(2))) {
        Edge<Vertex<int, int>, int, int> edge = *it3;
        cout << edge << endl;
        ++it3;
    }*/

    graphMenu();


    return 0;
}
