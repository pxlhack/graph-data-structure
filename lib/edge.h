#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "vertex.h"

template<class V, typename TData, typename TWeight>
class Edge {
public:
    Edge(V *v1, V *v2);

    Edge(V *v1, V *v2, TWeight weight);

    Edge(V *v1, V *v2, TWeight weight, TData data);

    V *getV1();

    V *getV2();

    TWeight getWeight();

    TData getData();

    void setWeight(TWeight weight);

    void setData(TData data);

private:
    V *vertex1, *vertex2;
    TWeight weight;
    TData data;
};

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2) {
    this->vertex1 = v1;
    this->vertex2 = v2;
}

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2, TWeight weight) {
    Edge<V, TData, TWeight>(v1, v2);
    this->weight = weight;
}

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2, TWeight weight, TData data) {
    Edge<V, TData, TWeight>(v1, v2, weight);
    this->data = data;
}

template<class V, typename TData, typename TWeight>
V *Edge<V, TData, TWeight>::getV1() {
    return vertex1;
}

template<class V, typename TData, typename TWeight>
V *Edge<V, TData, TWeight>::getV2() {
    return vertex2;
}

template<class V, typename TData, typename TWeight>
TWeight Edge<V, TData, TWeight>::getWeight() {
    return weight;
}

template<class V, typename TData, typename TWeight>
TData Edge<V, TData, TWeight>::getData() {
    return data;
}

template<class V, typename TData, typename TWeight>
void Edge<V, TData, TWeight>::setWeight(TWeight weight) {
    this->weight = weight;
}

template<class V, typename TData, typename TWeight>
void Edge<V, TData, TWeight>::setData(TData data) {
    this->data = data;
}


#endif //GRAPH_EDGE_H
