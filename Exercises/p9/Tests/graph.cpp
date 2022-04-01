// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

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

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    int count = 1;
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            count+=dfs(w);
    }
    return count;
}

int Graph::dfs(int v, list<int> &order) {
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w, order);
    }
    order.push_front(v);
    return 0;
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO
int Graph::outDegree(int v) {
    if(v>n || v<1) return -1;
    return nodes[v].adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int count=0;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].visited=false;
    }

    for(int j=1; j<nodes.size(); j++){
        if(nodes[j].visited==false){
            count++;
            dfs(j);
        }
    }

    return count;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int max=0, aux;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].visited=false;
    }

    for(int j=1; j<nodes.size(); j++){
        if(nodes[j].visited==false){
            aux=dfs(j);
            if(aux>max){
                max=aux;
            }
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;

    for(int i=1; i<nodes.size(); i++){
        nodes[i].visited= false;
    }

    for(int j=1; j<nodes.size(); j++){
        if(nodes[j].visited== false){
            dfs(j, order);
        }
    }

    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO
int Graph::distance(int a, int b) {
    nodes[a].distance=0;

    if(a==b) return 0;

    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(a);
    nodes[a]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance=nodes[u].distance+1;
                if(w==b) return nodes[w].distance;
            }
        }
    }
    return -1;
}

// ..............................
// b) Diametro
// TODO
int Graph::diameter() {
    if(connectedComponents()>1) return -1;

    int max;
    for(int v=1; v<nodes.size(); v++){
        nodes[v].distance=0;

        for (int v=1; v<=n; v++) nodes[v].visited = false;
        queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v]. visited = true;
        while (!q.empty()) { // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            cout << u << " "; // show node order
            for (auto e : nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance=nodes[u].distance+1;
                    if(nodes[w].distance>max) max=nodes[w].distance;
                }
            }
        }
    }

    return max;
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    return false;
}
