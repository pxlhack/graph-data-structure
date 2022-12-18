#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"


int main() {
    vector<Vertex<int, int> *> vertices;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, false, false);
    vertices.push_back(graph1.insertV());
    vertices.push_back(graph1.insertV());
    vertices.push_back(graph1.insertV());
    vertices.push_back(graph1.insertV());

    Edge<Vertex<int, int>, int, int> *edge;

    edge = graph1.insertEdge(vertices[0], vertices[1]);
    edge->setWeight(1);
    edge->setData(10);

    edge = graph1.insertEdge(vertices[1], vertices[3]);
    edge->setWeight(2);
    edge->setData(20);

    edge = graph1.insertEdge(vertices[2], vertices[2]);
    edge->setWeight(3);
    edge->setData(30);

    cout << graph1.toString() << endl;
    cout << graph1.isEdge(0, 1);
    cout << graph1.isEdge(2, 2);
    cout << graph1.isEdge(1, 3);
    cout << graph1.isEdge(3, 3);


    return 0;
}
