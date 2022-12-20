#ifndef GRAPH_GRAPH_MENU_H
#define GRAPH_GRAPH_MENU_H

#include <iostream>
#include <regex>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

#define intVertex Vertex<int, int>
#define intEdge Edge<intVertex, int, int>
#define intGraph Graph<intVertex, intEdge>


using namespace std;

#define HELP "Menu:\n\
1) Create new graph and random fill\n\
2) Draw graph\n\
0) Exit\n"

bool isPositiveValue(std::string_view s) {
    static const std::regex r(R"(\d{1,})");
    return regex_match(s.data(), r);
}

bool isValidCommand(const std::string &command) {
    return isPositiveValue(std::string_view(command));
}

void graphMenu() {
    intGraph *g = nullptr;
    bool isWorked = true;
    string command;
    do {
        cout << HELP;
        cout << ">";
        cin >> command;

        if (isValidCommand(command)) {
            int num = stoul(command);
            switch (num) {
                case 1: {
                    g = new intGraph(6, 12, false, true);
                    break;
                }
                case 2: {
                    if (!g) {
                        cout << "-- Graph is not created! --\n";
                        break;
                    }
                    if (g->getVertexNumber() == 0) {
                        cout << "-- Graph is empty! --\n";
                        break;
                    }

                    cout << "Vertices:\n";
                    auto it = graph1.vBegin();
                    while (it != graph1.vEnd()) {
                        Vertex<int, int> vertex = *it;
                        cout << vertex << endl;

                        ++it;
                    }

                    cout << "Edges:\n";
                    auto it2 = graph1.eBegin();
                    while (it2 != graph1.eEnd()) {
                        Edge<Vertex<int, int>, int, int> edge = *it2;
                        cout << edge << endl;
                        ++it2;
                    }


                    break;
                }
                case 3: {
                    break;
                }
                case 0: {
                    isWorked = false;
                    break;
                }
                default: {
                    cout << "!!! unknown command: " << command << " !!!" << endl;
                    break;
                }
            }
        } else {
            cout << "!!! unknown command: " << command << " !!!" << endl;
        }
    } while (isWorked);
}

#endif //GRAPH_GRAPH_MENU_H
