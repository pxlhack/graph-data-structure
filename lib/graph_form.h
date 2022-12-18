#ifndef GRAPH_GRAPH_FORM_H
#define GRAPH_GRAPH_FORM_H

#include "graph_vertex.h"
#include "graph_edge.h"
#include <vector>

template<class Vertex, class Edge>
class GraphForm {
public:
    virtual void setVector(vector<Vertex *> &vertexVector) = 0;

    GraphForm(bool directed) {
        this->directed = directed;
        edge_number = 0;
    }

    int V() {
        return vertexVector.size();
    }

    int E() {
        return edge_number;
    }

    Vertex *insertV() {
        Vertex* vertex = new Vertex();
        vertexVector.push_back(vertex);
        
    }

protected:
    int edge_number;
    bool directed;
    vector<Vertex *> vertexVector;
    vector<Edge *> edgeVector;
};


#endif //GRAPH_GRAPH_FORM_H
