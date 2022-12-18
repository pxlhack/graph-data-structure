#ifndef GRAPH_M_GRAPH_FORM_H
#define GRAPH_M_GRAPH_FORM_H

#include "graph_form.h"

template<class GraphVertex>
class MGraphForm : public GraphForm<GraphVertex> {
public:
    MGraphForm() {}

    void setVector(vector<GraphVertex*>& vertexVector) override {}
};


#endif //GRAPH_M_GRAPH_FORM_H
