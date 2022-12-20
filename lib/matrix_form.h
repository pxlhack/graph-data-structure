#ifndef GRAPH_MATRIX_FORM_H
#define GRAPH_MATRIX_FORM_H

#include "graph_form.h"

template<class V, class E>
class MatrixForm : public GraphForm<V, E> {

public:

    MatrixForm(bool directed) : GraphForm<V, E>(directed) {}

    E *insertEdge(V *vertex1, V *vertex2) override {
        int id1 = vertex1->getIndex(), id2 = vertex2->getIndex();
        E *edge = new E(vertex1, vertex2);
        if (id1 != -1 && id2 != -1 && this->container[id1][id2] == nullptr) {
            this->edgeNumber++;
            if (!this->directed) {
                this->container[id2][id1] = edge;
            }
            this->container[id1][id2] = edge;
            return edge;
        } else {
            return nullptr;
        }
    }

    V *insertVertex() override {
        V *vertex = new V();
        vertex->setIndex(this->vertexNumber++);
        vector<E *> vector_;
        this->container.push_back(vector_);
        for (int i = 0; i < this->vertexNumber; i++) {
            this->container[i].push_back(nullptr);  //push_backing in new column
            if (i < this->vertexNumber - 1)
                this->container[this->vertexNumber - 1].push_back(nullptr); //push_backing in new row
        }
        return vertex;
    };

    E *getEdge(V *vertex1, V *vertex2) override {
        int id1 = vertex1->getIndex(), id2 = vertex2->getIndex();
        return this->container[id1][id2];
    }

    bool deleteEdge(V *pVertex1, V *pVertex2) override {
        int id1 = pVertex1->getIndex(), id2 = pVertex2->getIndex();
        if (id1 != -1 && id2 != -1 && this->container[id1][id2] != nullptr) {
            this->edgeNumber--;
            free(this->container[id1][id2]);
            this->container[id1][id2] = nullptr;
            if (!this->directed) {
                this->container[id2][id1] = nullptr;
            }
            return true;
        }
        return false;
    }

    bool deleteVertex(V *pVertex) override {
        int id = pVertex->getIndex();
        if (id != -1) {
            for (int i = 0; i < this->vertexNumber; i++) {
                E *edge = this->container[id][i];
                if (edge) {
                    V *pVertex2 = (edge->getV1() == pVertex) ? edge->getV2() : edge->getV1();
                    deleteEdge(pVertex, pVertex2);
                }
                this->container[i].erase(this->container[i].begin() + id);
            }
            this->container.erase(this->container.begin() + id);
            this->vertexNumber--;
            return true;
        }
        return false;
    }

    void clear() override {

    }

    string toString(vector<V *> vertices) override {
        auto *sstr = new stringstream;

        for (int i = 0; i < this->vertexNumber; i++) {
            *sstr << " " << i << "[" << vertices[i]->getName() << "," << vertices[i]->getData() << "]";
        }
        *sstr << "\n";

        for (int i = 0; i < this->vertexNumber; i++) {
            *sstr << i << " ";
            for (int j = 0; j < this->vertexNumber; j++) {
                E *edge = this->container[i][j];
                if (edge) {
                    *sstr << "[" << edge->getWeight() << ", " << edge->getData() << "] ";
                } else {
                    *sstr << "null  ";
                }
            }
            *sstr << "\n";
        }
        return sstr->str();
    }
};


#endif //GRAPH_MATRIX_FORM_H
