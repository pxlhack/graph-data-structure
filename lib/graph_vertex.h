//
// Created by pxlhack on 07.12.22.
//

#ifndef GRAPH_GRAPH_VERTEX_H
#define GRAPH_GRAPH_VERTEX_H


#include <string>

using namespace std;

template<typename T>
class GraphVertex {
private:
    string name;
    T data;
    int index;
public:
    GraphVertex();

    GraphVertex(string name, T data);

    const string &getName() const;

    void setName(const string &name);

    T getData() const;

    void setData(T data);



};




#endif //GRAPH_GRAPH_VERTEX_H
