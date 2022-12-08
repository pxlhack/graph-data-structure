#include "../lib/graph.h"

template<class GraphVertex, class GraphEdge>
Graph<GraphVertex, GraphEdge>::Graph() {
    graphForm = new LGraphForm();
}