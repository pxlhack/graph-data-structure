#ifndef GRAPH_GRAPH_EDGE_H
#define GRAPH_GRAPH_EDGE_H

#include "lib/graph_vertex.h"

template<typename T, typename P>
class GraphEdge {
public:
    GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex);

    GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex, double weight);

    GraphEdge(const GraphVertex<T> &initialVertex, const GraphVertex<T> &finalVertex, double weight, P data);

    const GraphVertex<T> &getInitialVertex() const;

    const GraphVertex<T> &getFinalVertex() const;

    double getWeight() const;

    P getData() const;

    void setWeight(double weight);

    void setData(P data);

private:
    GraphVertex<T> initialVertex, finalVertex;
    double weight;
    P data;
};




#endif //GRAPH_GRAPH_EDGE_H
