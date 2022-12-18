#ifndef GRAPH_LINEAR_FORM_H
#define GRAPH_LINEAR_FORM_H

#include "graph_form.h"

template<class V, class E>
class LinearForm : public GraphForm<V, E> {
public:

    LinearForm(bool directed) : GraphForm<V, E>(directed) {
        cout << "LinearFrom()\n";
    }

    void setVector(vector<V *> &vertexVector) override {}
};


#endif //GRAPH_LINEAR_FORM_H
