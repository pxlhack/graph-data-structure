#include <iostream>
#include "lib/graph.h"
#include "lib/vertex.h"
#include "lib/edge.h"

//todo menu
//todo vIterator
//todo eIterator
//todo Iterator
// todo task2
// todo task3
int main() {
    vector<Vertex<int, int> *> v;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(5, 6, true, true);
    cout << graph1 << endl;
    auto it = graph1.vBegin();
    int i = 0;
    while (it != graph1.vEnd()) {
        cout << (*it).getName() << endl;
        cout << (*it).getData() << endl;
        i++;
        ++it;
    }
    cout << i;

    return 0;
}
