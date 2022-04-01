// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;// As the node been visited on a search?
        float distance;
        int predecessor;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    Graph();
    /**
    * @brief Default constructor of a LocalTT object
    * @param nodes is the number of nodes
    * @param dir is the direction, false (undirected) by default
    */
    Graph(int nodes, bool dir = false);

    /**
    * @brief Adds edge to the Graph
    * @param src is the source node
    * @param dest is the destiny node
    * @param weight is the weight of the edge
    */
    void addEdge(int src, int dest, int weight);

    /**
    * @brief Returns a vector with a sequence of nodes that represent the itinerary from o to d with the fewest stops,
    * based on BFS, with O(V+E) time complexity, (V from number of vertex, E for number of Edges)
    * @param o is the origin node
    * @param d is the destiny node
    */
    vector<int> bfs(int o, int d);

    /**
    * @brief Returns distance between the two given nodes
    * @param a is a node
    * @param b is a node
    */
    int dijkstra_distance(int a, int b);

    /**
    * @brief Returns a list with the shortest path between the two given nodes with O(|V^2|)
    * @param a is the node of origin
    * @param b is the node of destiny
    */
    list<int> dijkstra_path(int a, int b);
};

#endif
