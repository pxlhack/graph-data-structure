#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "vertex.h"

template<class V, typename TData, typename TWeight>
class Edge {
public:
    Edge(V *v1, V *v2) {
        this->v1 = v1;
        this->v2 = v2;
    };

    Edge(V *v1, V *v2, TWeight weight) {
        Edge(v1, v2);
        this->weight = weight;
    };

    Edge(V *v1, V *v2, TWeight weight, TData data) {
        Edge(v1, v2, weight);
        this->data = data;
    };

    V *getV1() {
        return v1;
    };

    V *getV2() {
        return v2;
    };

    TWeight getWeight() {
        return weight;
    };

    TData getData() {
        return data;
    };

    void setWeight(TWeight weight) {
        this->weight = weight;
    };

    void setData(TData data) {
        this->data = data;
    };

private:
    V *v1, *v2;
    TWeight weight;
    TData data;
};


#endif //GRAPH_EDGE_H
