#ifndef GRAPH_GRAPH_EDGE_H
#define GRAPH_GRAPH_EDGE_H

#include "graph_vertex.h"

template<class GraphVertex, typename TData, typename TWeight>
class GraphEdge {
public:
    GraphEdge(const GraphVertex &initialVertex, const GraphVertex &finalVertex);

    GraphEdge(const GraphVertex &initialVertex, const GraphVertex &finalVertex, TWeight weight);

    GraphEdge(const GraphVertex &initialVertex, const GraphVertex &finalVertex, TWeight weight, TData data);

    const GraphVertex &getInitialVertex() const;

    const GraphVertex &getFinalVertex() const;

    TWeight getWeight() const;

    TData getData() const;

    void setWeight(TWeight weight);

    void setData(TData data);

private:
    GraphVertex initialVertex, finalVertex;
    TWeight weight;
    TData data;
};

#endif //GRAPH_GRAPH_EDGE_H
