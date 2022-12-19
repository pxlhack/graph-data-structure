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
        E *oldEdge = getEdge(pVertex1, pVertex2);

        if (oldEdge) {
            return nullptr;
        } else {
            this->container[id1].push_back(edge);
            this->edgeNumber++;
            if (!this->directed && id1 != id2) {
                this->container[id2].push_back(edge);
            }
            return edge;
        }

    }


    V *insertVertex() override {
        V *vertex = new V();
        vertex->setIndex(this->vertexNumber++);
        vector<E *> vector_;
        this->container.push_back(vector_);
        return vertex;
    };

    E *getEdge(V *pVertex1, V *pVertex2) override {
        int id1 = pVertex1->getIndex();
        vector<E *> edgeVector = this->container[id1];
        for (int i = 0; i < edgeVector.size(); i++) {
            if (edgeVector[i]->getV1() == pVertex1 && edgeVector[i]->getV2() == pVertex2) {
                return edgeVector[i];
            }
        }
        return nullptr;
    }

    bool deleteEdge(V *pVertex1, V *pVertex2) override {
        int id1 = pVertex1->getIndex(), id2 = pVertex2->getIndex();
        if (id1 != -1 && id2 != -1) {
            if (!this->directed) {

                for (int i = 0; i < this->container[id1].size(); i++) {
                    E *edge = getEdge(pVertex1, pVertex2);
                    if (edge) {
                        this->container[id1].erase(this->container[id1].begin() + i);
                        break;
                    }
                }

                for (int i = 0; i < this->container[id2].size(); i++) {
                    E *edge = getEdge(pVertex2, pVertex1);
                    if (edge) {
                        free(this->container[id2][i]);
                        this->container[id2].erase(this->container[id2].begin() + i);
                        this->edgeNumber--;
                        return true;
                    }
                }
            } else {
                for (int i = 0; i < this->container[id1].size(); i++) {
                    if (this->container[id1][i]->getV1() == pVertex1 && this->container[id1][i]->getV2() == pVertex2) {
                        free(this->container[id1][i]);
                        this->container[id1].erase(this->container[id1].begin() + i);
                        this->edgeNumber--;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool deleteVertex(V *v) override {
        int id = v->getIndex();
        for (int i = 0; i < this->container[id].size(); i++) {
            E *edge = this->container[id][i];
            V *V2 = (edge->getV1() == v) ? edge->getV2() : edge->getV1();
            deleteEdge(v, V2);
        }
        this->container.erase(this->container.begin() + id);
        this->vertexNumber--;
        return true;
    }

    void clear() override {

    }

    string toString(vector<V *> vertices) override {
        stringstream *sstr = new stringstream;
        for (int i = 0; i < this->vertexNumber; i++) {
            *sstr << i << "[" << vertices[i]->getName() << "," << vertices[i]->getName() << "]: ";
            for (int j = 0; j < this->container[i].size(); j++) {
                E *edge = this->container[i][j];
                *sstr << "[" << edge->getV1()->getIndex() << ","
                      << edge->getV2()->getIndex() << ",w(" << edge->getWeight() << "),d("
                      << edge->getData()
                      << ")] ";
            }
            *sstr << "\n";
        }
        return sstr->str();
    }

};


#endif //GRAPH_LIST_FORM_H
