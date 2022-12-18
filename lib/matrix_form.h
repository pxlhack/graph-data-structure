#ifndef GRAPH_MATRIX_FORM_H
#define GRAPH_MATRIX_FORM_H

#include "graph_form.h"

template<class V, class E>
class MatrixForm : public GraphForm<V, E> {
public:
    MatrixForm(bool directed) : GraphForm<V, E>(directed) {}

    E *insertEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        V1->setIndex(id1);
        V2->setIndex(id2);
        E *edge = new E(V1, V2);
        if (id1 != -1 && id2 != -1 && this->container[id1][id2] == nullptr) {
            this->edge_number++;
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
        this->vertices.push_back(vertex);
        this->vertex_number++;
        vector<E *> vector_;
        this->container.push_back(vector_);
        for (int i = 0; i < this->vertex_number; i++) {
            this->container[i].push_back(nullptr);  //push_backing in new column
            if (i < this->vertex_number - 1)
                this->container[this->vertex_number - 1].push_back(nullptr); //push_backing in new row
        }
        return vertex;
    };

    E *getEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        return this->container[id1][id2];
    }

    bool insertEdge(int v1, int v2, E *t) {
        int size = this->container.size(); //Число вершин
        //Неверный номер вершины
        if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size) return false;
        //Петля или ребро уже есть
        if (v1 == v2 || this->container[v1][v2] != nullptr) return false;
        //Вставляем ребро
        this->container[v1][v2] = t;
        return true;
    }

    E *getEdge(int v1, int v2) {
        int size = this->container.size(); //Число вершин
        //Неверный номер вершины
        if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
            throw 1;
        if (v1 == v2 || this->container[v1][v2] == nullptr)//Петля
            throw 1;
        return this->container[v1][v2];
    }

    bool deleteEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        if (id1 != -1 && id2 != -1 && this->container[id1][id2] != nullptr) {
            this->edge_number--;
            free(this->container[id1][id2]);
            this->container[id1][id2] = nullptr;
            if (!this->directed)
                this->container[id2][id1] = nullptr;
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
                this->container[i].erase(this->container[i].begin() + id);
            }
            this->container.erase(this->container.begin() + id);
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


    bool hasEdge(int v1, int v2) {
        int size = this->container.size(); //Число вершин
        //Неверный номер вершины
        if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
            return false;
        if (v1 == v2) //Петля
            return false;
        if (this->container[v1][v2] != nullptr)
            return true;
        return false;
    }

    bool isEdge(int id1, int id2) override {
        //для неорграфа
        E *e1 = this->container[id1][id2];
        E *e2 = this->container[id2][id1];
        return e1 && e2;
    };
};


#endif //GRAPH_MATRIX_FORM_H
