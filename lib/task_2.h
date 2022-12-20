#ifndef GRAPH_TASK_2_H
#define GRAPH_TASK_2_H

#include "graph.h"

template<class V, class E>
class Task2 {
public:
    Task2(Graph<V, E> *g) {
        this->g = g;
        solve();
    }

    Task2(Task2 &t) {
        this = t;
    }

    ~Task2() {}

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
            g->toList();
            auto *listForm = dynamic_cast<ListForm<V, E> *>(g->graphForm);

            bool *visited = new bool[g->getVertexNumber()];
            for (int j = 0; j < g->getVertexNumber(); ++j) {
                visited[j] = false;
            }

            vector<int> path;
            int i = 0;
            cout << "Cycles with " + to_string(i) + ":\n";
            listForm->task2(i, i, visited, path);
        } else {
            cout << "Graph is not directed!\n";
        }
    }

    Graph<V, E> *g;
};


#endif //GRAPH_TASK_2_H
