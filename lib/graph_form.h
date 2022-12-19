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
        this->edgeNumber = 0;
        this->vertexNumber = 0;
    }

    int getVertexNumber() {
        return this->vertexNumber;
    }

    int getEdgeNumber() {
        return edgeNumber;
    }

    virtual V *insertVertex() = 0;

    virtual E *insertEdge(V *pVertex1, V *pVertex2) = 0;

    virtual E *getEdge(V *V1, V *V2) = 0;

    virtual E *createEdge(int index1, int index2) = 0;

    virtual bool deleteEdge(V *V1, V *V2) = 0;

    virtual bool deleteVertex(V *v) = 0;

    virtual void clear() = 0;

    virtual std::string toString() = 0;

    virtual bool isEdge(int id1, int id2) = 0;

protected:
    int vertexNumber;
    int edgeNumber;
    bool directed;
    vector<vector<E *>> container;
};


#endif //GRAPH_GRAPH_FORM_H
