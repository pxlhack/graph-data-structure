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
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        E *edge = new E(V1, V2);
        if (id1 != -1 && id2 != -1 && this->list[id1][id2] == nullptr) {
            this->edge_number++;
            if (!this->directed) {
                this->list[id2][id1] = edge;
            }
            this->list[id1][id2] = edge;
            return edge;
        } else {
            return nullptr;
        }
    }

    V *insertVertex() override {
        V *vertex = new V();
        this->vertices.push_back(vertex);
        this->vertex_number++;
        vector<E *> vector_;
        this->list.push_back(vector_);
        for (int i = 0; i < this->vertex_number; i++) {
            this->list[i].push_back(nullptr);  //push_backing in new column
            if (i < this->vertex_number - 1)
                this->list[this->vertex_number - 1].push_back(nullptr); //push_backing in new row
        }
        return vertex;
    };

    E *getEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        return this->list[id1][id2];
    }

    bool deleteEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        if (id1 != -1 && id2 != -1 && this->list[id1][id2] != nullptr) {
            this->edge_number--;
            free(this->list[id1][id2]);
            this->list[id1][id2] = nullptr;
            if (!this->directed)
                this->list[id2][id1] = nullptr;
            return true;
        }
        return false;
    }

    bool deleteVertex(V *v) override {
        int id = GraphForm<V, E>::getId(v);
        if (id != -1) {
            for (int i = 0; i < this->vertex_number; i++) {
                deleteEdge(this->vertices[id], this->vertices[i]);
                deleteEdge(this->vertices[i], this->vertices[id]);
                this->list[i].erase(this->list[i].begin() + id);
            }
            this->list.erase(this->list.begin() + id);
            free(this->vertices[id]);
            this->vertices.erase(this->vertices.begin() + id);
            this->vertex_number--;
            return true;
        }
        return false;
    }

    void clear() override {

    }

    string toString() override {
        stringstream *sstr = new stringstream;
        for (int i = 0; i < this->vertex_number; i++) {
            *sstr << " " << i << "[" << this->vertices[i]->getName() << "," << this->vertices[i]->getData() << "]";
        }
        *sstr << "\n";
        for (int i = 0; i < this->vertex_number; i++) {
            *sstr << i << " ";
            for (int j = 0; j < this->vertex_number; j++) {
                E *edge = this->list[i][j];
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
