#include "../lib/graph_vertex.h"


template<typename T>
GraphVertex<T>::GraphVertex() {

}

template<typename T>
GraphVertex<T>::GraphVertex(string name, T data) {

}

template<typename T>
void GraphVertex<T>::setData(T data) {
    GraphVertex::data = data;
}
template<typename T>
T GraphVertex<T>::getData() const {
    return data;
}

template<typename T>
const string &GraphVertex<T>::getName() const {
    return name;
}

template<typename T>
void GraphVertex<T>::setName(const string &name) {
    GraphVertex::name = name;
}