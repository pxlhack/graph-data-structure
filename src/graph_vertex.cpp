#include "../lib/graph_vertex.h"

template<typename TData,typename TName>
GraphVertex<TData, TName>::GraphVertex() {

}

template<typename TData,typename TName>
GraphVertex<TData, TName>::GraphVertex(TName name, TData data) {

}

template<typename TData,typename TName>
TData GraphVertex<TData, TName>::getData() const {
    return nullptr;
}

template<typename TData,typename TName>
void GraphVertex<TData, TName>::setData(TData data) {

}

template<typename TData,typename TName>
TName GraphVertex<TData, TName>::getName() const {
    return name;
}

template<typename TData,typename TName>
void GraphVertex<TData, TName>::setName(TName name) {
    GraphVertex::name = name;
}