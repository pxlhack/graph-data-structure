#ifndef GRAPH_L_GRAPH_FORM_H
#define GRAPH_L_GRAPH_FORM_H

#include "graph_form.h"

template<class GraphVertex>
class LGraphForm : public GraphForm<GraphVertex> {
public:
    LGraphForm() {
        cout <<"LGraphFrom constructor\n";
    }

    void setVector(vector<GraphVertex*>& vertexVector) override {}
};


#endif //GRAPH_L_GRAPH_FORM_H
