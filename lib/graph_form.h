#ifndef GRAPH_GRAPH_FORM_H
#define GRAPH_GRAPH_FORM_H

#include "vertex.h"
#include "edge.h"
#include <vector>
#include <sstream>
#include <unordered_set>

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


    virtual bool deleteEdge(V *V1, V *V2) = 0;

    virtual bool deleteVertex(V *v) = 0;

    virtual void clear() = 0;

    virtual std::string toString(vector<V *> vertices) = 0;

    vector<E *> getEdgesVector() {
        vector<E *> edges = vector<E *>();
        if (this->directed) {
            for (vector<E *> ev: this->container) {
                for (E *e: ev) {
                    if (e) {
                        edges.insert(edges.begin(), e);
                    }
                }
            }
        } else {
            unordered_set<E *> set;
            for (vector<E *> ev: this->container) {
                for (E *e: ev) {
                    if (e) {
                        set.insert(e);
                    }
                }
            }
            for (E *e: set) {
                edges.insert(edges.begin(), e);
            }
        }

        return edges;
    }

    vector<E *> getEdgesVector(V *vertex) {
        vector<E *> allEdges = getEdgesVector();
        vector<E *> edges = vector<E *>();
        if (directed) {
            for (E *e: allEdges) {
                if (vertex == e->getV1()) {
                    edges.insert(edges.begin(), e);
                }
            }
        } else {
            for (E *e: allEdges) {
                if (vertex == e->getV1() || vertex == e->getV2()) {
                    edges.insert(edges.begin(), e);
                }
            }
        }

        return edges;
    }


protected:
    int vertexNumber;
    int edgeNumber;
    bool directed;
    vector<vector<E *>> container;
};


#endif //GRAPH_GRAPH_FORM_H
