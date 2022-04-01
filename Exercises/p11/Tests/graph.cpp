// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include "graph.h"
#include <climits>

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
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
int Graph::dijkstra_distance(int a, int b) {

    MinHeap<int, int> aux(nodes.size(), -1);
    int u;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].dist=INT_MAX;
        nodes[i].visited= false;
        aux.insert(i, nodes[i].dist);
    }

    nodes[a].dist=0;
    aux.decreaseKey(a, 0);

    while(aux.getSize()>0){
        u=aux.removeMin();
        nodes[u].visited=true;
        for(auto e: nodes[u].adj){
            if(nodes[e.dest].visited==false && nodes[u].dist+e.weight<nodes[e.dest].dist){
                nodes[e.dest].dist=nodes[u].dist+e.weight;
                aux.decreaseKey(e.dest, nodes[e.dest].dist);
            }
        }
    }

    if(nodes[b].dist==INT_MAX) return -1;
    else return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {
    list<int> path;

    MinHeap<int, int> aux(nodes.size(), -1);
    int u;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].dist=INT_MAX;
        nodes[i].visited= false;
        aux.insert(i, nodes[i].dist);
    }

    nodes[a].dist=0;
    nodes[a].pred=a;
    aux.decreaseKey(a, 0);

    while(aux.getSize()>0){
        u=aux.removeMin();
        nodes[u].visited=true;
        for(auto e: nodes[u].adj){
            if(nodes[e.dest].visited==false && nodes[u].dist+e.weight<nodes[e.dest].dist){
                nodes[e.dest].dist=nodes[u].dist+e.weight;
                aux.decreaseKey(e.dest, nodes[e.dest].dist);
                nodes[e.dest].pred=u;
            }
        }
    }


    if(nodes[b].dist==INT_MAX){
        return path;
    }
    else{
        int j=b;
        path.push_back(b);
        while(j!=a){
            j=nodes[j].pred;
            path.push_front(j);
        }
        return path;
    }

}
