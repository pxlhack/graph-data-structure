#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"


//todo menu
//todo vIterator
//todo eIterator
//todo Iterator
// todo task2
// todo task3
int main() {
    vector<Vertex<int, int> *> v;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(6, 8, false, true);
    cout << graph1 << endl;

    vector<Edge<Vertex<int, int>, int, int> *> eV = graph1.getEdgesVector();
    for (Edge<Vertex<int, int>, int, int> *e: eV) {
        cout << e->getV1()->getIndex() << " " << e->getV2()->getIndex() << endl;
    }
    /*auto it = graph1.vBegin();
    int i = 0;
    while (it != graph1.vEnd()) {
        cout << (*it).getName() << endl;
        cout << (*it).getData() << endl;
        i++;
        ++it;
    }
    cout << i << endl;

    auto *t = new unordered_set<Vertex<int, int> *>();
    Vertex<int, int> *vertex = new Vertex<int, int>(10, 10);
    Vertex<int, int> *vertex2 = new Vertex<int, int>(20, 20);

    t->insert(vertex);
    t->insert(vertex2);
    t->insert(vertex2);
    t->insert(vertex2);
    t->insert(vertex2);
    for (Vertex<int, int> *v1: *t) {
        cout << v1->getData() << endl;
    }*/

    return 0;
}
