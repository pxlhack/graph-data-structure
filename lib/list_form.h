#ifndef GRAPH_LIST_FORM_H
#define GRAPH_LIST_FORM_H

#include "graph_form.h"

template<class V, class E>
class ListForm : public GraphForm<V, E> {
public:

    E *createEdge(int index1, int index2) override {
        return nullptr;
    }

    ListForm(bool directed) : GraphForm<V, E>(directed) {
    }

    E *insertEdge(V *pVertex1, V *pVertex2) override {
        int id1 = pVertex1->getIndex(), id2 = pVertex2->getIndex();

        E *edge = new E(pVertex1, pVertex2);
        for (int i = 0; i < this->container[id1].size(); i++) {
            if (!this->directed && isDesired(pVertex1, pVertex2, this->container[id1][i]))
                return nullptr;
            if (this->directed &&
                ((this->container[id1][i])->getV1() == pVertex1 && this->container[id1][i]->getV2() == pVertex2))
                return nullptr;
        }
        this->container[id1].push_back(edge);
        this->edgeNumber++;
        if (!this->directed && id1 != id2)
            this->container[id2].push_back(edge);
        return edge;
    }


    V *insertVertex() override {
        V *vertex = new V();
        vertex->setIndex(this->vertexNumber++);
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
                        this->edgeNumber--;
                        return true;
                    }
            } else {
                for (int i = 0; i < this->container[id1].size(); i++)
                    if (this->container[id1][i]->getV1() == V1 && this->container[id1][i]->getV2() == V2) {
                        free(this->container[id1][i]);
                        this->container[id1].erase(this->container[id1].begin() + i);
                        this->edgeNumber--;
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

    bool isEdge(int id1, int id2) override {
        vector<E *> edgeVector = this->container[id1];
        V *v1 = this->vertices[id1];
        V *v2 = this->vertices[id2];

        for (E *e: edgeVector) {
            bool flag = isDesired(v1, v2, e);
            if (flag) return true;
        }
        return false;
    };


private:
    bool isDesired(V *V1, V *V2, E *e) {
        return (e->getV1() == V1 && e->getV2() == V2) || (e->getV1() == V2 && e->getV2() == V1);
    }

};


#endif //GRAPH_LIST_FORM_H
