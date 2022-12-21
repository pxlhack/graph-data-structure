#ifndef GRAPH_TASK_2_H
#define GRAPH_TASK_2_H

#include "graph.h"

template<class V, class E>
class Task2 {
public:
    Task2(Graph<V, E> *g);

    Task2(Task2 &t) {
        this = t;
    }

    ~Task2() {}

    void set(Graph<V, E> *g);

    void restart();

private:
    void solve();

    vector<vector<int>> cyclesVector;
    Graph<V, E> *g;
};

template<class V, class E>
Task2<V, E>::Task2(Graph<V, E> *g) {
    this->g = g;
    solve();
}

template<class V, class E>
void Task2<V, E>::solve() {
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
        cyclesVector = listForm->getCyclesVector();
        listForm->clearCycles();
        for (vector<int> p: cyclesVector) {
            for (int v: p) {
                cout << to_string(v) + " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Graph is not directed!\n";
    }
}

template<class V, class E>
void Task2<V, E>::set(Graph<V, E> *g) {
    this->g = g;
    solve();
}

template<class V, class E>
void Task2<V, E>::restart() {
    solve();
}


#endif //GRAPH_TASK_2_H
