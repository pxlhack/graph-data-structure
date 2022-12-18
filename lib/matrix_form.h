#ifndef GRAPH_MATRIX_FORM_H
#define GRAPH_MATRIX_FORM_H

#include "graph_form.h"

template<class V, class E>
class MatrixForm : public GraphForm<V, E> {
public:
    MatrixForm(bool directed) : GraphForm<V, E>(directed) {
        cout << "MatrixFrom()\n";
    }

    void setVector(vector<V *> &vertexVector) override {}
};


#endif //GRAPH_MATRIX_FORM_H
