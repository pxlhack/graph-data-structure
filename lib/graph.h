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
    };


    Graph(int vertexNumber, bool directed = false, bool dense = true) {
        this->directed = directed;

        if (dense) {
            graphForm = new LinearForm<V, E>(directed);
        } else {
            graphForm = new MatrixForm<V, E>(directed);
        }

        for (int i = 0; i < vertexNumber; ++i) {
            graphForm->insertVertex();
        }
    }


    Graph(int vertexNumber, int edgeNumber, bool directed = false, bool dense = true) {
        this->directed = directed;
        if (dense) {
            graphForm = new LinearForm<V, E>(directed);
        } else {
            graphForm = new MatrixForm<V, E>(directed);
        }
        if (directed) {
            int max_edges = (vertexNumber * (vertexNumber - 1) + vertexNumber);
            if (edgeNumber > max_edges) edgeNumber = max_edges;
        } else {
            int max_edges = (vertexNumber * (vertexNumber - 1) / 2 + vertexNumber);
            if (edgeNumber > max_edges) edgeNumber = max_edges;
        }
        vector<V *> vertices;
        for (int i = 0; i < vertexNumber; i++) {
            V *vertex = graphForm->insertVertex();
            vertices.push_back(vertex);
        }
        srand(time(NULL));
        for (int i = 0; i < edgeNumber;) {
            int id1 = rand() % vertexNumber;
            int id2 = rand() % vertexNumber;
            E *edge = graphForm->insertEdge(vertices[id1], vertices[id2]);
            if (edge != nullptr)
                i++;
        }
    };

    int getVertexNumber() {
        return this->graphForm->getVertexNumber();
    };

    int getEdgeNumber() {
        return this->graphForm->getEdgeNumber();
    };

    bool isDirected() const {
        return directed;
    }

    bool isDense() {
        return dynamic_cast<const LinearForm<V *, E>>(graphForm);
    }

    double K() {
        double e = this->graphForm->getEdgeNumber();
        double v = this->graphForm->getVertexNumber();
        return directed ? (e / (v * (v - 1))) : (2 * e / (v * (v - 1)));
    };

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
