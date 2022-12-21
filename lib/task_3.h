#ifndef GRAPH_TASK_3_H
#define GRAPH_TASK_3_H

#include "graph.h"

#include <iostream>

template<class V, class E>
class Task3 {
public:
    Task3(Graph<V, E> *g);

    Task3(Task3 &t);

    ~Task3() {}

    void set(Graph<V, E> *g);

    void restart();

    int result();

private:
    void solve();

    int centerIndex;

    Graph<V, E> *g;
};

template<class V, class E>
Task3<V, E>::Task3(Graph<V, E> *g) {
    this->g = g;
    solve();
}

template<class V, class E>
void Task3<V, E>::solve() {
    if (g->isDirected()) {
        g->toMatrix();
        auto *pMatrixForm = dynamic_cast<MatrixForm<V, E> *>(g->graphForm);

        centerIndex = pMatrixForm->task3();
        std::cout << "Graph center: " + to_string(centerIndex) + "\n";
    } else {
        std::cout << "Graph is not directed!\n";
    }
}

template<class V, class E>
void Task3<V, E>::set(Graph<V, E> *g) {
    this->g = g;
    solve();
}

template<class V, class E>
int Task3<V, E>::result() {
    return centerIndex;
}

template<class V, class E>
void Task3<V, E>::restart() {
    solve();
}

template<class V, class E>
Task3<V, E>::Task3(Task3 &t) {
    this = t;
}


#endif //GRAPH_TASK_3_H
