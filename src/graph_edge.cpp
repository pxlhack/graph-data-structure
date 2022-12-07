#include "../lib/graph_edge.h"

template<class GraphVertex, typename TData, typename TWeight>
GraphEdge<GraphVertex, TData, TWeight>::GraphEdge(const GraphVertex &initialVertex,
                                                  const GraphVertex &finalVertex) {
    this->initialVertex = initialVertex;
    this->finalVertex = finalVertex;
}

template<class GraphVertex, typename TData, typename TWeight>
GraphEdge<GraphVertex, TData, TWeight>::GraphEdge(const GraphVertex &initialVertex,
                                                  const GraphVertex &finalVertex,
                                                  TWeight weight) {
    GraphEdge<GraphVertex, TData, TWeight>(initialVertex, finalVertex);
    this->weight = weight;
}

template<class GraphVertex, typename TData, typename TWeight>
GraphEdge<GraphVertex, TData, TWeight>::GraphEdge(const GraphVertex &initialVertex,
                                                  const GraphVertex &finalVertex,
                                                  TWeight weight,
                                                  TData data) {
    GraphEdge<GraphVertex, TData, TWeight>(initialVertex, finalVertex, weight);
    this->data = data;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &GraphEdge<GraphVertex, TData, TWeight>::getInitialVertex() const {
    return initialVertex;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &GraphEdge<GraphVertex, TData, TWeight>::getFinalVertex() const {
    return finalVertex;
}

template<class GraphVertex, typename TData, typename TWeight>
TWeight GraphEdge<GraphVertex, TData, TWeight>::getWeight() const {
    return weight;
}

template<class GraphVertex, typename TData, typename TWeight>
TData GraphEdge<GraphVertex, TData, TWeight>::getData() const {
    return data;
}

template<class GraphVertex, typename TData, typename TWeight>
void GraphEdge<GraphVertex, TData, TWeight>::setWeight(TWeight weight) {
    this->weight = weight;
}

template<class GraphVertex, typename TData, typename TWeight>
void GraphEdge<GraphVertex, TData, TWeight>::setData(TData data) {
    this->data = data;
}

