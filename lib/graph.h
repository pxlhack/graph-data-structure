#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <vector>
#include "graph_vertex.h"
#include "graph_edge.h"
#include "graph_form.h"
#include "l_graph_form.h"
#include "m_graph_form.h"

using namespace std;

#define V GraphVertex
#define E GraphEdge


template<class V, class E>
class Graph {
public:
    Graph();

    bool isDirected() const {
        return directed;
    }

    bool isDense()  {
        return dynamic_cast<const LGraphForm *>(graphForm);
    };


private:
    GraphForm *graphForm;
    bool directed;
    vector<V> vertexVector;
};




#endif //GRAPH_GRAPH_H
