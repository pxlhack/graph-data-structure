#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <vector>
#include "graph_vertex.h"
#include "graph_edge.h"
#include "graph_form.h"
#include "l_graph_form.h"
#include "m_graph_form.h"

using namespace std;


template<class GraphVertex, class GraphEdge>
class Graph {
public:
    Graph();

    Graph(int v, bool directed = false, bool dense = true) {
        Graph();
        if (!dense) {
            graphForm = new MGraphForm<GraphVertex *>();
        }
        this->directed = directed;
        for (int i = 0; i < v; ++i) {
            addVertex();
        }
        std::cout << vertexVector.size() << std::endl;
        graphForm->setVector(vertexVector);
    }

    Graph(int V, int E, bool directed = false, bool dense = true);

    int V();

    int E();

    bool isDirected() const {
        return directed;
    }

    bool isDense() {
        return dynamic_cast<const LGraphForm<GraphVertex> *>(graphForm);
    }

    double K();

    GraphVertex *InsertV();

    bool DeleteV(GraphVertex*V);

    bool deleteE(GraphVertex* vertex1, GraphVertex* vertex2);

    GraphEdge* getEdge(GraphVertex * vertex1, GraphVertex* vertex2);

    GraphEdge* InsertE(GraphVertex *vertex1, GraphVertex* vertex2);

private:
    bool directed;
    GraphForm<GraphVertex *> *graphForm;
    vector<GraphVertex *> vertexVector;
};

template<class GraphVertex, class GraphEdge>
Graph<GraphVertex, GraphEdge>::Graph() {
    graphForm = new LGraphForm<GraphVertex *>();
    directed = false;
}


#endif //GRAPH_GRAPH_H
