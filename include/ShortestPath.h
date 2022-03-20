//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_SHORTESTPATH_H
#define WEEK3_SHORTESTPATH_H


#include <map>
#include <set>
#include "Graph.h"
#include "PriorityQueue.h"


class ShortestPath {
public:
    explicit ShortestPath(Graph &g);
    // Find the shortest path between two nodes
    std::list<Edge> path(Node* source, Node* destination);

    // Find the distance of the shortest path between two nodes
    double path_size(Node* source, Node* destination);

    // Reset
    void reset();
private:
    Graph & graph;
    PriorityQueue<Node *> openset = {};
    std::set<Node *> closedset = {};
    std::vector<std::list<Edge>> paths = {};

    // One step of the search
    void onestep();
};


#endif //WEEK3_SHORTESTPATH_H
