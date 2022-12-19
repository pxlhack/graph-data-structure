#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"


int main() {
    vector<Vertex<int, int> *> v;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, false, true);
    v.push_back(graph1.insertV());
    v.push_back(graph1.insertV());
    v.push_back(graph1.insertV());
    v.push_back(graph1.insertV());

    Edge<Vertex<int, int>, int, int> *edge;

    edge = graph1.insertEdge(v[0], v[1]);
    edge->setWeight(1);
    edge->setData(10);

    edge = graph1.insertEdge(v[1], v[3]);
    edge->setWeight(2);
    edge->setData(20);

    edge = graph1.insertEdge(v[2], v[2]);
    edge->setWeight(3);
    edge->setData(30);

    bool isDense = graph1.isDense();
    for (int i = 0; i < 10; ++i) {
        if (isDense) {
            graph1.toMatrix();
        } else {
            graph1.toList();
        }
        isDense = !isDense;
        cout << graph1 << endl;
    }


    return 0;
}
