// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#include "graph.h"
#include "minHeap.h"

Graph ::Graph() {}

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

vector<int> Graph::bfs(int o, int d) {
    vector<int> ant;
    for(int v=1; v<=n; v++){
        nodes[v].visited = false;
        ant.push_back(-1);
    }
    queue<int> q;

    q.push(o);
    nodes[o].visited = true;
    nodes.at(o).distance = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;

            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes.at(w).distance = nodes.at(u).distance + 1;
                ant[w]=u;

                if(w==d){
                    while(!q.empty()){
                        q.pop();
                    }
                }
            }
        }
    }

    vector<int> stops;
    int aux=d;
    stops.push_back(aux);
    while(ant[aux]!=-1){
        stops.push_back(ant[aux]);
        aux=ant[aux];
    }

   /* cout << "The sequence of stops to follow are: ";
    for(int i=stops.size()-1; i>=0; i--){

        cout << stops[i] << " ";
    }*/

    return stops;
}

int Graph::dijkstra_distance(int a, int b) {
    MinHeap<int, int> heap(nodes.size(), -1);

    int u, v, max = INT_MAX;

    for(int i = 1; i < nodes.size(); i++){
        nodes.at(i).distance = max;
        nodes.at(i).visited = false;
        heap.insert(i, max);
    }

    nodes.at(a).distance = 0;
    nodes.at(a).predecessor = a;

    heap.decreaseKey(a, 0);

    while(heap.getSize() > 0){

        u = heap.removeMin();
        nodes.at(u).visited = true;

        for(auto e : nodes.at(u).adj){
            v = e.dest;
            if(nodes.at(v).visited == false && nodes.at(u).distance + e.weight < nodes.at(v).distance) {
                nodes.at(v).distance = nodes.at(u).distance + e.weight;
                //heap.decreaseKey(v, nodes.at(v).distance);
                nodes.at(v).predecessor = u;
                heap.decreaseKey(v, nodes.at(v).distance);
            }
        }
    }
    if(nodes.at(b).distance == max) {
        return -1;
    }
    else {
        return nodes.at(b).distance;
    }
}

list<int> Graph::dijkstra_path(int a, int b) {
    list<int> stops;
    int aux = b;

    dijkstra_distance(a, b);
    stops.push_front(b);

    while(a != b){
        if(nodes.at(b).predecessor == b) {
            stops.clear();
            return stops;
        }

        b = nodes.at(aux).predecessor;
        aux = b;
        stops.push_front(b);
    }
    return stops;
}

