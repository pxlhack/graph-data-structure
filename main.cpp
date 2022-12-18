#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"


int main() {
    vector<Vertex<int, int> *> vertices;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, false, true);
    cout << graph1.toString();
    vertices.push_back(graph1.insertV());
    cout << graph1.toString();
    vertices.push_back(graph1.insertV());
    cout << graph1.toString();
    vertices.push_back(graph1.insertV());
    cout << graph1.toString();

    Edge<Vertex<int, int>, int, int> *edge = graph1.insertEdge(vertices[0], vertices[1]);
    edge->setWeight(1);
    edge->setData(10);
    cout << graph1.toString();

    edge = graph1.insertEdge(vertices[1], vertices[1]);
    edge->setWeight(2);
    edge->setData(20);

    cout << graph1.toString();
    cout << "edge[0,1] = " << graph1.getEdge(vertices[0], vertices[1]) << "\n";
    cout << "edge[1,1] = " << graph1.getEdge(vertices[1], vertices[1]) << "\n";
    graph1.DeleteV(vertices[1]);
    cout << graph1.toString();


    return 0;
}
