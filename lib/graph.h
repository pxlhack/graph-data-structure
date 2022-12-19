#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <vector>
#include "vertex.h"
#include "edge.h"
#include "graph_form.h"
#include "list_form.h"
#include "matrix_form.h"

using namespace std;


template<class V, class E>
class Graph {
public:
    Graph() {
        directed = false;
        graphForm = new ListForm<V, E>(false);
    };


    Graph(int vertexNumber, bool directed = false, bool dense = true) {
        this->directed = directed;

        if (dense) {
            graphForm = new ListForm<V, E>(directed);
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
            graphForm = new ListForm<V, E>(directed);
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
        return dynamic_cast<ListForm<V, E> *>(graphForm);
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

    bool deleteV(V *pVertex) {
        bool isDeleted = graphForm->deleteVertex(pVertex);
        if (isDeleted) {
            vertices.erase(vertices.begin() + pVertex->getIndex());
            for (int i = 0; i < vertices.size(); i++) {
                vertices[i]->setIndex(i);
            }
        }
        return isDeleted;
    };

    bool deleteE(V *vertex1, V *vertex2) {
        return graphForm->deleteEdge(vertex1, vertex2);
    };

    E *getEdge(V *vertex1, V *vertex2) {
        return graphForm->getEdge(vertex1, vertex2);
    };

    E *insertEdge(V *vertex1, V *vertex2) {
        return graphForm->insertEdge(vertex1, vertex2);
    };



    /*void toList() {
        if (!isDense()) {
            GraphForm<V, E> *newForm = new ListForm<V, E>(this->directed);
            vector<V *> vector1;
            for (int i = 0; i < vertices.size(); ++i) {
                V *vertex = newForm->insertVertex();
                vertex->setName(vertices[i]->getName());
                vertex->setData(vertices[i]->getData());
                vector1.push_back(vertex);
            }


            for (int i = 0; i < vertices.size(); ++i) {
                for (int j = 0; j < vertices.size(); ++j) {
                    if (graphForm->isEdge(i, j,vertices)) {
                        E *newEdge = newForm->insertEdge(vector1[i], vector1[j]);
                        if (newEdge) {
                            E *oldEdge = graphForm->getEdge(vertices[i], vertices[j]);

                        }
                    }
                }
            }
            delete graphForm;
            graphForm = newForm;
            vertices = vector1;
        }
    }*/


    /*void toMatrix() {
        if (isDense()) {
            GraphForm<V, E> *newForm = new MatrixForm<V, E>(this->directed);
            vector<V *> vector1;
            for (int i = 0; i < vertices.size(); ++i) {
                V *vertex = newForm->insertVertex();
                vertex->setName(vertices[i]->getName());
                vertex->setData(vertices[i]->getData());
                vector1.push_back(vertex);
            }

            for (int i = 0; i < vertices.size(); ++i) {
                for (int j = 0; j < vertices.size(); ++j) {
                    if (graphForm->isEdge(i, j,vertices)) {
                        E *e = newForm->insertEdge(vector1[i], vector1[j]);
                        e->setWeight(getEdge(vertices[i], vertices[j])->getWeight());
                        e->setData(getEdge(vertices[i], vertices[j])->getData());
                    }
                }
            }
            delete graphForm;
            graphForm = newForm;
            vertices = vector1;
        }
    }*/

    std::string toString() {
        return graphForm->toString(vertices);
    }

private:
    bool directed;
    GraphForm<V, E> *graphForm;
    vector<V *> vertices;
};


#endif //GRAPH_GRAPH_H
