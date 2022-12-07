#include "graph_edge.h"

template<typename T, typename P>
GraphEdge<T, P>::GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex) {
    this->initialVertex = initialVertex;
    this->finalVertex = finalVertex;
}

template<typename T, typename P>
GraphEdge<T, P>::GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex, double weight) {
    GraphEdge<T, P>(initialVertex, finalVertex);
    this->weight = weight;
}

template<typename T, typename P>
GraphEdge<T, P>::GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex, double weight,
                           P data) {
    GraphEdge<T, P>(initialVertex, finalVertex, weight);
    this->data = data;
}

template<typename T, typename P>
const GraphVertex<T> &GraphEdge<T, P>::getInitialVertex() const {
    return initialVertex;
}

template<typename T, typename P>
const GraphVertex<T> &GraphEdge<T, P>::getFinalVertex() const {
    return finalVertex;
}

template<typename T, typename P>
double GraphEdge<T, P>::getWeight() const {
    return weight;
}

template<typename T, typename P>
P GraphEdge<T, P>::getData() const {
    return data;
}

template<typename T, typename P>
void GraphEdge<T, P>::setWeight(double weight) {
    GraphEdge::weight = weight;
}

template<typename T, typename P>
void GraphEdge<T, P>::setData(P data) {
    GraphEdge::data = data;
}

