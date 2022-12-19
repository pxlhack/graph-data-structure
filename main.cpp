#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"


int main() {
    vector<Vertex<int, int> *> v;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, false, false);
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

    cout << graph1.toString() << endl;

    edge = graph1.getEdge(v[1], v[0]);
    if (edge) {
        cout << edge->getData() << endl;
    }

    graph1.deleteE(v[2], v[2]);
    edge = graph1.getEdge(v[2], v[2]);
    if (edge) {
        cout << edge->getData() << endl;
    }

    edge = graph1.getEdge(v[3], v[1]);
    if (edge) {
        cout << edge->getData() << endl;
    }
    graph1.deleteV(v[2]);
    cout << graph1.toString() << endl;

    return 0;
}
