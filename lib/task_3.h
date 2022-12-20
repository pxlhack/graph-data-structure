#ifndef GRAPH_TASK_3_H
#define GRAPH_TASK_3_H

#include "graph.h"

#include <iostream>

template<class V, class E>
class Task3 {
public:
    Task3(Graph<V, E> *g) {
        this->g = g;
        solve();
    }

    Task3(Task3 &t) {
        this = t;
    }

    ~Task3() {}

    void set(Graph<V, E> *g) {
        this->g = g;
        solve();
    }

    void restart() {
        solve();
    }

private:
    void solve() {
        if (g->isDirected()) {
            g->toMatrix();
            auto *pMatrixForm = dynamic_cast<MatrixForm<V, E> *>(g->graphForm);

            int index = pMatrixForm->task3();
            std::cout << "Graph center: " + to_string(index) + "\n";
        } else {
            std::cout << "Graph is not directed!\n";
        }
    }

    Graph<V, E> *g;
};


#endif //GRAPH_TASK_3_H
