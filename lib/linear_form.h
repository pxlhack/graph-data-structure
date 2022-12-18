#ifndef GRAPH_LINEAR_FORM_H
#define GRAPH_LINEAR_FORM_H

#include "graph_form.h"

template<class V, class E>
class LinearForm : public GraphForm<V, E> {
public:

    LinearForm(bool directed) : GraphForm<V, E>(directed) {
        cout << "LinearFrom()\n";
    }

    E *insertEdge(V *V1, V *V2) override {
        int id1 = GraphForm<V, E>::getId(V1), id2 = GraphForm<V, E>::getId(V2);
        E *edge = new E(V1, V2);
        for (int i = 0; i < this->list[id1].size(); i++) {
            if (!this->directed && isDesired(V1, V2, this->list[id1][i]))
                return nullptr;
            if (this->directed && ((this->list[id1][i])->getV1() == V1 && this->list[id1][i]->getV2() == V2))
                return nullptr;
        }
        this->list[id1].push_back(edge);
        this->edge_number++;
        if (!this->directed && id1 != id2)
            this->list[id2].push_back(edge);
        return edge;
    }

    V *insertVertex() override {
        V *vertex = new V();
        this->vertices.push_back(vertex);
        this->vertex_number++;
        vector<E *> vector_;
        this->list.push_back(vector_);
        return vertex;
    };

    E *getEdge(V *V1, V *V2) override {
        return nullptr;
    }

    bool deleteEdge(V *V1, V *V2) override {
        return false;
    }

    bool deleteVertex(V *v) override {
        return false;
    }

    void clear() override {

    }

    string toString() override {
        stringstream *sstr = new stringstream;
        for (int i = 0; i < this->vertex_number; i++) {
            *sstr << i << "[" << this->vertices[i]->getName() << "," << this->vertices[i]->getName() << "]: ";
            for (int j = 0; j < this->list[i].size(); j++) {
                E *edge = this->list[i][j];
                *sstr << "[" << GraphForm<V, E>::getId(edge->getV1()) << ","
                      << GraphForm<V, E>::getId(edge->getV2()) << ",w(" << edge->getWeight() << "),d(" << edge->getData()
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


#endif //GRAPH_LINEAR_FORM_H
