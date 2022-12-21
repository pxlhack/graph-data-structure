#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

using namespace std;

template<typename TData, typename TName>
class Vertex {
public:
    Vertex();

    Vertex(TName name, TData data);

    TData getData();

    void setData(TData data);

    TName getName();

    void setName(TName name);

    int getIndex() const;

    void setIndex(int index);

    friend std::ostream &operator<<(std::ostream &out, Vertex &vertex){

            out << vertex.toString();
            return out;

    }

private:

    string toString();

    TData data;
    TName name;
    int index;
};

template<typename TData, typename TName>
Vertex<TData, TName>::Vertex() {
    data = TData(0);
    name = TName(0);
    index = -1;
}

template<typename TData, typename TName>
Vertex<TData, TName>::Vertex(TName name, TData data) {
    Vertex();
    this->data = data;
    this->name = name;
}

template<typename TData, typename TName>
TData Vertex<TData, TName>::getData() {
    return this->data;
}

template<typename TData, typename TName>
string Vertex<TData, TName>::toString() {
    string s = "{ i: " + to_string(index) + " Data: " + to_string(data) + " Name: " + to_string(name) + " }";
    return s;
}



template<typename TData, typename TName>
void Vertex<TData, TName>::setIndex(int index) {
    this->index = index;
}

template<typename TData, typename TName>
int Vertex<TData, TName>::getIndex() const {
    return index;
}

template<typename TData, typename TName>
void Vertex<TData, TName>::setName(TName name) {
    this->name = name;
}

template<typename TData, typename TName>
TName Vertex<TData, TName>::getName() {
    return this->name;
}

template<typename TData, typename TName>
void Vertex<TData, TName>::setData(TData data) {
    this->data = data;
}


#endif //GRAPH_VERTEX_H
