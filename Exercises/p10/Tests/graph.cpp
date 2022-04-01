// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// Exercicio 3: Algoritmo de Prim
// ----------------------------------------------------------
// TODO
int Graph::prim(int r) {

    MinHeap<int, int> q(nodes.size(), -1);
    int u, ret=0;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].distance=INT_MAX;
        nodes[i].parent=0;
    }
    nodes[r].distance=0;

    for(int j=1; j<nodes.size(); j++){
        q.insert(j, nodes[j].distance);
    }

    while(q.getSize()>0){
        u=q.removeMin();
        for(auto e: nodes[u].adj){
            q.decreaseKey(e.dest, e.weight);
            if(q.hasKey(e.dest) && e.weight<nodes[e.dest].distance){
                nodes[e.dest].parent=u;
                nodes[e.dest].distance=e.weight;
            }
        }
    }

    for (int k=1; k<nodes.size(); k++){
        ret+=nodes[k].distance;
    }

    return ret;
}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
// TODO
int Graph::kruskal() {

    DisjointSets<int> s;

    for(int i=1; i<nodes.size(); i++){
        s.makeSet(i);
    }

    //sort???

    for(int j=1; j<nodes.size(); j++){
        for(auto e: nodes[j].adj){
            if(s.find(j)!=s.find(e.dest)){
                s.unite(j, e.dest);
            }
        }
    }

    return 0;
}
