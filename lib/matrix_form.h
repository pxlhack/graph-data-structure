#ifndef GRAPH_MATRIX_FORM_H
#define GRAPH_MATRIX_FORM_H

#include "graph_form.h"

template<class V, class E>
class MatrixForm : public GraphForm<V, E> {
public:
    MatrixForm(bool directed) : GraphForm<V, E>(directed) {
        cout << "MatrixFrom()\n";
    }

    E *insertEdge(V *V1, V *V2) override {
        return nullptr;
    }

    V *insertVertex() override {
        return nullptr;
    };

    E *getEdge(V *V1, V *V2) override {
        return nullptr;
    }

    bool deleteEdge(V *V1, V *V2) override {
        return false;
    }

    bool deleteVertex(V *V1, V *V2) override {
        return false;
    }

    void clear() override {

    }

    string toString() override {
        return " ";
    }
};


#endif //GRAPH_MATRIX_FORM_H
