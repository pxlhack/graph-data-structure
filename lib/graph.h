#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <vector>
#include "vertex.h"
#include "edge.h"
#include "graph_form.h"
#include "linear_form.h"
#include "matrix_form.h"

using namespace std;


template<class V, class E>
class Graph {
public:
    Graph();


    Graph(int vCount, bool directed = false, bool dense = true) {
        this->directed = directed;

        if (dense) {
            graphForm = new LinearForm<V, E>(directed);
        } else {
            graphForm = new MatrixForm<V, E>(directed);
        }

        for (int i = 0; i < vCount; ++i) {
            graphForm->insertVertex();
        }
        cout << "Graph(vCount, directed, dense)\n";
    }


    Graph(int vCount, int eCount, bool directed = false, bool dense = true);

    int vCount();

    int eCount();

    bool isDirected() const {
        return directed;
    }

    bool isDense() {
        return dynamic_cast<const LinearForm<V *, E>>(graphForm);
    }

    double K();

    V *InsertV();

    bool DeleteV(V *vertex);

    bool deleteE(V *vertex1, V *vertex2);

    E *getEdge(V *vertex1, V *vertex2);

    E *InsertE(V *vertex1, V *vertex2);

private:
    bool directed;
    GraphForm<V, E> *graphForm;
    vector<V *> vertices;
};

template<class V, class E>
Graph<V, E>::Graph() {
    directed = false;
    graphForm = new LinearForm<V, E>(false);
    cout << "Graph()\n";
}


#endif //GRAPH_GRAPH_H
