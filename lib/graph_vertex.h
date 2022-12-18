#ifndef GRAPH_GRAPH_VERTEX_H
#define GRAPH_GRAPH_VERTEX_H

using namespace std;

template<typename TData, typename TName>
class Vertex {
private:
    TData *data;
    TName *name;
    int index;
public:
    Vertex();

    Vertex(TName name, TData data);

    TData getData() const;

    void setData(TData data);

    TName getName() const;

    void setName(TName name);
};

template<typename TData, typename TName>
Vertex<TData, TName>::Vertex() {
    data = nullptr;
    name = nullptr;
    index = 0;
    std::cout << "vertex created\n";
}

template<typename TData, typename TName>
Vertex<TData, TName>::Vertex(TName name, TData data) {

}

template<typename TData, typename TName>
TData Vertex<TData, TName>::getData() const {
    return data;
}

template<typename TData, typename TName>
void Vertex<TData, TName>::setData(TData data) {

}

template<typename TData, typename TName>
TName Vertex<TData, TName>::getName() const {
    return name;
}

template<typename TData, typename TName>
void Vertex<TData, TName>::setName(TName name) {
    Vertex::name = name;
}

#endif //GRAPH_GRAPH_VERTEX_H
