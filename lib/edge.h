#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "vertex.h"

template<class Vertex, typename TData, typename TWeight>
class Edge {
public:
    Edge(const Vertex &v1, const Vertex &v2);

    Edge(const Vertex &v1, const Vertex &v2, TWeight weight);

    Edge(const Vertex &v1, const Vertex &v2, TWeight weight, TData data);

    const Vertex &getV1() const;

    const Vertex &getV2() const;

    TWeight getWeight() const;

    TData getData() const;

    void setWeight(TWeight weight);

    void setData(TData data);

private:
    Vertex vertex1, vertex2;
    TWeight weight;
    TData data;
};

template<class Vertex, typename TData, typename TWeight>
Edge<Vertex, TData, TWeight>::Edge(const Vertex &v1, const Vertex &v2) {
    this->vertex1 = v1;
    this->vertex2 = v2;
}

template<class GraphVertex, typename TData, typename TWeight>
Edge<GraphVertex, TData, TWeight>::Edge(const GraphVertex &v1, const GraphVertex &v2, TWeight weight) {
    Edge<GraphVertex, TData, TWeight>(v1, v2);
    this->weight = weight;
}

template<class GraphVertex, typename TData, typename TWeight>
Edge<GraphVertex, TData, TWeight>::Edge(const GraphVertex &v1, const GraphVertex &v2, TWeight weight, TData data) {
    Edge<GraphVertex, TData, TWeight>(v1, v2, weight);
    this->data = data;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &Edge<GraphVertex, TData, TWeight>::getV1() const {
    return vertex1;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &Edge<GraphVertex, TData, TWeight>::getV2() const {
    return vertex2;
}

template<class GraphVertex, typename TData, typename TWeight>
TWeight Edge<GraphVertex, TData, TWeight>::getWeight() const {
    return weight;
}

template<class GraphVertex, typename TData, typename TWeight>
TData Edge<GraphVertex, TData, TWeight>::getData() const {
    return data;
}

template<class GraphVertex, typename TData, typename TWeight>
void Edge<GraphVertex, TData, TWeight>::setWeight(TWeight weight) {
    this->weight = weight;
}

template<class GraphVertex, typename TData, typename TWeight>
void Edge<GraphVertex, TData, TWeight>::setData(TData data) {
    this->data = data;
}


#endif //GRAPH_EDGE_H
