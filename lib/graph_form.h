#ifndef GRAPH_GRAPH_FORM_H
#define GRAPH_GRAPH_FORM_H

#include "vertex.h"
#include "edge.h"
#include <vector>

template<class V, class E>
class GraphForm {
public:
    virtual void setVector(vector<V *> &vertexVector) = 0;

    GraphForm(bool directed) {
        this->directed = directed;
        edge_number = 0;
    }

    int getVertexNumber() {
        return vertexVector.size();
    }

    int getEdgeNumber() {
        return edge_number;
    }

    V *insertVertex() {
        V *vertex = new V();
        vertexVector.push_back(vertex);
        return vertex;
    }

protected:
    int edge_number;
    bool directed;
    vector<V *> vertexVector;
    vector<E *> edgeVector;
};


#endif //GRAPH_GRAPH_FORM_H
