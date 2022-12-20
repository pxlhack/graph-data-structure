import random

import networkx as nx
import matplotlib.pyplot as plt

graph_chars = []
typeFile = open('../graph_type.txt', 'r')
for line in typeFile:
    graph_chars.append(int(line))
typeFile.close()

isDirected = graph_chars[0]
vNumber = graph_chars[1]
eNumber = graph_chars[2]

G = nx.Graph()
if isDirected == 1:
    G = nx.DiGraph()

vertices = []
vFile = open('../vertices.txt', 'r')
for line in vFile:
    vertices.append(int(line))
vFile.close()

eArray = []
eFile = open('../edges.txt', 'r')
for line in eFile:
    eArray.append(int(line))
eFile.close()

edges = []
for i in range(eNumber):
    v1 = eArray[3 * i]
    v2 = eArray[3 * i + 1]
    weight = eArray[3 * i + 2]
    edges.append([v1, v2, weight])

vRandX = vertices[:]
vRandY = vertices[:]
for v in vertices:
    x = random.choice(vRandX)
    y = random.choice(vRandY)
    vRandX.remove(x)
    vRandY.remove(y)
    G.add_node(v, pos=(x, y))

for e in edges:
    G.add_edge(e[0], e[1], weight=e[2])

plt.figure(figsize=(16, 9))
pos = nx.get_node_attributes(G, 'pos')
nx.draw(G, pos, with_labels=1)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.savefig("../graph.png")
plt.show()
