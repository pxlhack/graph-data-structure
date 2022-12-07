#ifndef GRAPH_GRAPH_VERTEX_H
#define GRAPH_GRAPH_VERTEX_H

using namespace std;

template<typename TData, typename TName>
class GraphVertex {
private:
    TData data;
    TName name;
    int index;
public:
    GraphVertex();

    GraphVertex(TName name, TData data);

    TData getData() const;

    void setData(TData data);

    TName getName() const;

    void setName(TName name);
};

#endif //GRAPH_GRAPH_VERTEX_H
