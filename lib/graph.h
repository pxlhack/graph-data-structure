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
    Graph() {
        directed = false;
        graphForm = new LinearForm<V, E>(false);
        cout << "Graph()\n";
    };


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


    Graph(int vCount, int eCount, bool directed = false, bool dense = true) {
        this->directed = directed;
        if (dense) {
            graphForm = new LinearForm<V, E>(directed);
        } else {
            graphForm = new MatrixForm<V, E>(directed);
        }
        if (directed) {
            int max_edges = (vCount * (vCount - 1) + vCount);
            if (eCount > max_edges) eCount = max_edges;
        } else {
            int max_edges = (vCount * (vCount - 1) / 2 + vCount);
            if (eCount > max_edges) eCount = max_edges;
        }
        vector<V *> vertices;
        for (int i = 0; i < vCount; i++) {
            V *vertex = graphForm->insertVertex();
            vertices.push_back(vertex);
        }
        srand(time(NULL));
        for (int i = 0; i < eCount;) {
            int id1 = rand() % vCount;
            int id2 = rand() % vCount;
            E *edge = graphForm->insertEdge(vertices[id1], vertices[id2]);
            if (edge != nullptr)
                i++;
        }
        cout << "Graph(), dense = " << dense << "\n";
    };

    int vCount() {
        return 0;
    };

    int eCount() {
        return 0;
    };

    bool isDirected() const {
        return directed;
    }

    bool isDense() {
        return dynamic_cast<const LinearForm<V *, E>>(graphForm);
    }

    double K();

    V *insertV() {
        V *vertex = graphForm->insertVertex();
        vertices.push_back(vertex);
        return vertex;
    };

    bool DeleteV(V *vertex) {
        return false;
    };

    bool deleteE(V *vertex1, V *vertex2) {
        return false;
    };

    E *getEdge(V *vertex1, V *vertex2) {
        return nullptr;
    };

    E *insertEdge(V *vertex1, V *vertex2) {
        return graphForm->insertEdge(vertex1, vertex2);
    };

    std::string toString() {
        return graphForm->toString();
    }

private:
    bool directed;
    GraphForm<V, E> *graphForm;
    vector<V *> vertices;
};


#endif //GRAPH_GRAPH_H
