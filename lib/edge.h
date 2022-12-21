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

    friend std::ostream &operator<<(std::ostream &out, Edge &edge){
        out << edge.toString();
        return out;
    }

private:
    string toString();

    V *v1, *v2;
    TWeight weight;
    TData data;
};

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2) {
    this->v1 = v1;
    this->v2 = v2;
}

template<class V, typename TData, typename TWeight>
string Edge<V, TData, TWeight>::toString() {
    int index1 = v1->getIndex();
    int index2 = v2->getIndex();
    string s = "{ [" + to_string(index1) + ", " + to_string(index2) + "] Weight: " + to_string(weight) +
               " Data: " + to_string(data) + " }";
    return s;
}


template<class V, typename TData, typename TWeight>
void Edge<V, TData, TWeight>::setData(TData data) {
    this->data = data;
}

template<class V, typename TData, typename TWeight>
void Edge<V, TData, TWeight>::setWeight(TWeight weight) {
    this->weight = weight;
}

template<class V, typename TData, typename TWeight>
TData Edge<V, TData, TWeight>::getData() {
    return data;
}

template<class V, typename TData, typename TWeight>
TWeight Edge<V, TData, TWeight>::getWeight() {
    return weight;
}

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2, TWeight weight) {
    Edge(v1, v2);
    this->weight = weight;
}

template<class V, typename TData, typename TWeight>
V *Edge<V, TData, TWeight>::getV1() {
    return v1;
}

template<class V, typename TData, typename TWeight>
V *Edge<V, TData, TWeight>::getV2() {
    return v2;
}

template<class V, typename TData, typename TWeight>
Edge<V, TData, TWeight>::Edge(V *v1, V *v2, TWeight weight, TData data) {
    Edge(v1, v2, weight);
    this->data = data;
}


#endif //GRAPH_EDGE_H
