#ifndef GRAPH_GRAPH_MENU_H
#define GRAPH_GRAPH_MENU_H

#include <iostream>
#include <regex>
#include <fstream>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

#define intVertex Vertex<int, int>
#define intEdge Edge<intVertex, int, int>
#define intGraph Graph<intVertex, intEdge>


using namespace std;

#define HELP "Menu:\n\
1) Create new graph and random fill\n\
2) Create empty graph\n\
3) Draw graph\n\
4) Add vertex\n\
5) Add edge\n\
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

                // random Graph
                case 1: {
                    cout << "Random graph:\n";
                    cout << "Enter vertex number\n";
                    unsigned v = 0;
                    cout << ">";

                    cin >> v;
                    cout << "Enter edge number \n";
                    unsigned e = 0;
                    cout << ">";
                    cin >> e;

                    cout << "Enter 0) not directed 1) directed \n";
                    bool directed;
                    cout << ">";
                    cin >> directed;

                    cout << "Enter 0) not dense 1) dense \n";
                    bool dense;
                    cout << ">";
                    cin >> dense;

                    g = new intGraph(v, e, directed, dense);
                    break;
                }

                    // empty Graph
                case 2: {
                    g = new intGraph();
                    break;
                }

                    //  draw graph
                case 3: {
                    if (!g) {
                        cout << "-- Graph is not created! --\n";
                        break;
                    }
                    if (g->getVertexNumber() == 0) {
                        cout << "-- Graph is empty! --\n";
                        break;
                    }

                    cout << "Vertices:\n";
                    auto it = g->vBegin();
                    while (it != g->vEnd()) {
                        intVertex vertex = *it;
                        cout << vertex << endl;

                        ++it;
                    }

                    cout << "Edges:\n";
                    auto it2 = g->eBegin();
                    while (it2 != g->eEnd()) {
                        intEdge edge = *it2;
                        cout << edge << endl;
                        ++it2;
                    }

                    ofstream fout;
                    fout.open("../graph_type.txt");
                    if (!fout.is_open()) {
                        cout << "File is not opened!\n";
                    } else {

                        if (g->isDirected()) {
                            fout << "1\n";
                        } else {
                            fout << "0\n";
                        }

                        fout << to_string(g->getVertexNumber()) + "\n";
                        fout << to_string(g->getEdgeNumber()) + "\n";

                    }

                    fout.close();


                    fout.open("../vertices.txt");
                    if (!fout.is_open()) {
                        cout << "File is not opened!\n";
                    } else {

                        auto it = g->vBegin();
                        while (it != g->vEnd()) {
                            intVertex vertex = *it;
                            fout << to_string(vertex.getIndex()) + "\n";
                            ++it;
                        }


                    }

                    fout.close();

                    fout.open("../edges.txt");
                    if (!fout.is_open()) {
                        cout << "File is not opened!\n";
                    } else {

                        auto it2 = g->eBegin();
                        while (it2 != g->eEnd()) {
                            intEdge edge = *it2;
                            intVertex *v1 = edge.getV1();
                            intVertex *v2 = edge.getV2();
                            fout << to_string(v1->getIndex()) + "\n";
                            fout << to_string(v2->getIndex()) + "\n";
                            fout << to_string(edge.getWeight()) + "\n";
                            ++it2;
                        }


                    }

                    fout.close();

                    system("python3 ../graph.py");


                    break;
                }

                    //  add vertex
                case 4: {
                    if (!g) {
                        cout << "-- Graph is not created! --\n";
                        break;
                    }

                    cout << "Add vertex\n";
                    int name, data;
                    cout << "Enter name:";
                    cin >> name;
                    cout << "Enter data:";
                    cin >> data;
                    intVertex *v = g->insertV();
                    v->setData(data);
                    v->setName(name);

                    break;
                }

                    // add edge
                case 5: {
                    if (!g) {
                        cout << "-- Graph is not created! --\n";
                        break;
                    }

                    cout << "Add edge\n";
                    int i1, i2;
                    cout << "Enter index1:";
                    cin >> i1;
                    cout << "Enter index2:";
                    cin >> i2;
                    intVertex *v1 = g->get(i1);
                    intVertex *v2 = g->get(i2);
                    if (v1 && v2) {
                        intEdge *edge = g->insertEdge(v1, v2);
                        if (edge) {
                            cout << "~~ Added! ~~\n";
                            int data, weight;
                            cout << "Enter data:";
                            cin >> data;
                            cout << "\nEnter weight:";
                            cin >> weight;
                            edge->setData(data);
                            edge->setWeight(weight);
                        } else {
                            cout << "-- Edge already exists! --\n";
                        }
                    } else {
                        cout << "-- there are no such vertices! --\n";
                    }
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
