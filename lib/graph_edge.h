#ifndef GRAPH_GRAPH_EDGE_H
#define GRAPH_GRAPH_EDGE_H

#include "graph_vertex.h"

template<class Vertex, typename TData, typename TWeight>
class Edge {
public:
    Edge(const Vertex &initialVertex, const Vertex &finalVertex);

    Edge(const Vertex &initialVertex, const Vertex &finalVertex, TWeight weight);

    Edge(const Vertex &initialVertex, const Vertex &finalVertex, TWeight weight, TData data);

    const Vertex &getInitialVertex() const;

    const Vertex &getFinalVertex() const;

    TWeight getWeight() const;

    TData getData() const;

    void setWeight(TWeight weight);

    void setData(TData data);

private:
    Vertex initialVertex, finalVertex;
    TWeight weight;
    TData data;
};

template<class Vertex, typename TData, typename TWeight>
Edge<Vertex, TData, TWeight>::Edge(const Vertex &initialVertex,
                                   const Vertex &finalVertex) {
    this->initialVertex = initialVertex;
    this->finalVertex = finalVertex;
}

template<class GraphVertex, typename TData, typename TWeight>
Edge<GraphVertex, TData, TWeight>::Edge(const GraphVertex &initialVertex,
                                        const GraphVertex &finalVertex,
                                        TWeight weight) {
    Edge<GraphVertex, TData, TWeight>(initialVertex, finalVertex);
    this->weight = weight;
}

template<class GraphVertex, typename TData, typename TWeight>
Edge<GraphVertex, TData, TWeight>::Edge(const GraphVertex &initialVertex,
                                        const GraphVertex &finalVertex,
                                        TWeight weight,
                                        TData data) {
    Edge<GraphVertex, TData, TWeight>(initialVertex, finalVertex, weight);
    this->data = data;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &Edge<GraphVertex, TData, TWeight>::getInitialVertex() const {
    return initialVertex;
}

template<class GraphVertex, typename TData, typename TWeight>
const GraphVertex &Edge<GraphVertex, TData, TWeight>::getFinalVertex() const {
    return finalVertex;
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



#endif //GRAPH_GRAPH_EDGE_H
