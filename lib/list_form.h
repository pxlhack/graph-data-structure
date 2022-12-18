#ifndef GRAPH_LIST_FORM_H
#define GRAPH_LIST_FORM_H

#include "graph_form.h"

template<class V, class E>
class ListForm : public GraphForm<V, E> {
public:

    ListForm(bool directed) : GraphForm<V, E>(directed) {
    }

    E *insertEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        E *edge = new E(V1, V2);
        for (int i = 0; i < this->container[id1].size(); i++) {
            if (!this->directed && isDesired(V1, V2, this->container[id1][i]))
                return nullptr;
            if (this->directed && ((this->container[id1][i])->getV1() == V1 && this->container[id1][i]->getV2() == V2))
                return nullptr;
        }
        this->container[id1].push_back(edge);
        this->edge_number++;
        if (!this->directed && id1 != id2)
            this->container[id2].push_back(edge);
        return edge;
    }

    V *insertVertex() override {
        V *vertex = new V();
        this->vertices.push_back(vertex);
        this->vertex_number++;
        vector<E *> vector_;
        this->container.push_back(vector_);
        return vertex;
    };

    E *getEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1);
        for (int i = 0; i < this->container[id1].size(); i++)
            if (this->container[id1][i]->getV2() == V2 && this->container[id1][i]->getV1() == V1)
                return this->container[id1][i];
        return nullptr;
    }

    bool deleteEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        if (id1 != -1 && id2 != -1) {
            if (!this->directed) {
                for (int i = 0; i < this->container[id1].size(); i++)
                    if (isDesired(V1, V2, this->container[id1][i])) {
                        this->container[id1].erase(this->container[id1].begin() + i);
                        break;
                    }
                for (int i = 0; i < this->container[id2].size(); i++)
                    if (isDesired(V1, V2, this->container[id2][i])) {
                        free(this->container[id2][i]);
                        this->container[id2].erase(this->container[id2].begin() + i);
                        this->edge_number--;
                        return true;
                    }
            } else {
                for (int i = 0; i < this->container[id1].size(); i++)
                    if (this->container[id1][i]->getV1() == V1 && this->container[id1][i]->getV2() == V2) {
                        free(this->container[id1][i]);
                        this->container[id1].erase(this->container[id1].begin() + i);
                        this->edge_number--;
                        return true;
                    }
            }
        }
        return false;
    }

    bool deleteVertex(V *v) override {
        int id = GraphForm<V, E>::getId(v);

        for (int i = 0; i < this->vertex_number; i++) {
            deleteEdge(v, this->vertices[i]);
            if (this->directed)
                deleteEdge(this->vertices[i], v);
        }
        this->container.erase(this->container.begin() + id);
        free(this->vertices[id]);
        this->vertices.erase(this->vertices.begin() + id);
        this->vertex_number--;
        return false;
    }

    void clear() override {

    }

    string toString() override {
        stringstream *sstr = new stringstream;
        for (int i = 0; i < this->vertex_number; i++) {
            *sstr << i << "[" << this->vertices[i]->getName() << "," << this->vertices[i]->getName() << "]: ";
            for (int j = 0; j < this->container[i].size(); j++) {
                E *edge = this->container[i][j];
                *sstr << "[" << GraphForm<V, E>::getId(edge->getV1()) << ","
                      << GraphForm<V, E>::getId(edge->getV2()) << ",w(" << edge->getWeight() << "),d("
                      << edge->getData()
                      << ")] ";
            }
            *sstr << "\n";
        }
        return sstr->str();
    }

private:
    bool isDesired(V *V1, V *V2, E *e) {
        return (e->getV1() == V1 && e->getV2() == V2) || (e->getV1() == V2 && e->getV2() == V1);
    }

};


#endif //GRAPH_LIST_FORM_H
