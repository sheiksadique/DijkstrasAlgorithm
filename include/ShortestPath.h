//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_SHORTESTPATH_H
#define WEEK3_SHORTESTPATH_H


#include <map>
#include <set>
#include "Graph.h"
#include "PriorityQueue.h"

typedef pair<int, double> maptype;

class ShortestPath {
public:
    explicit ShortestPath(Graph &g);
    // Find the shortest path between two nodes
    list<Edge> path(Node* source, Node* destination);

    // Find the distance of the shortest path between two nodes
    double path_size(Node* source, Node* destination);

    // Reset
    void reset();
private:
    Graph & graph;
    PriorityQueue<Node *> openset = {};
    set<Node *> closedset = {};
    vector<list<Edge>> paths = {};

    // One step of the search
    void onestep();
};


#endif //WEEK3_SHORTESTPATH_H
