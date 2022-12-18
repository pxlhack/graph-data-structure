#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

using namespace std;

template<typename TData, typename TName>
class Vertex {
public:
    Vertex() {
        data = TData(0);
        name = TName(0);
        index = -1;
    };

    Vertex(TName name, TData data) {
        Vertex();
        this->data = data;
        this->name = name;
    };

    TData getData() {
        return this->data;
    };

    void setData(TData data) {
        this->data = data;
    };

    TName getName() {
        return this->name;
    };

    void setName(TName name) {
        this->name = name;
    };

private:
    TData data;
    TName name;
    int index;
};


#endif //GRAPH_VERTEX_H
