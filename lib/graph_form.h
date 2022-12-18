#ifndef GRAPH_GRAPH_FORM_H
#define GRAPH_GRAPH_FORM_H

#include "vertex.h"
#include "edge.h"
#include <vector>
#include <sstream>

template<class V, class E>
class GraphForm {
public:

    GraphForm(bool directed) {
        this->directed = directed;
        this->edge_number = 0;
        this->vertex_number = 0;
    }

    int getVertexNumber() {
        return vertices.size();
    }

    int getEdgeNumber() {
        return edge_number;
    }

    virtual V *insertVertex() = 0;

    virtual E *insertEdge(V *V1, V *V2) = 0;

    virtual E *getEdge(V *V1, V *V2) = 0;

    virtual bool deleteEdge(V *V1, V *V2) = 0;

    virtual bool deleteVertex(V *v) = 0;

    virtual void clear() = 0;

    virtual std::string toString() = 0;

protected:
    int edge_number;
    int vertex_number;
    bool directed;
    vector<V *> vertices;
    vector<vector<E *>> container;


    int getId(V *v) {
        int id = -1;
        for (int i = 0; i < vertex_number && id == -1; i++)
            if (vertices[i] == v)
                id = i;
        return id;
    }

};


#endif //GRAPH_GRAPH_FORM_H
