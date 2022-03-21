//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_SHORTESTPATH_H
#define WEEK3_SHORTESTPATH_H


#include <set>
#include "Graph.h"
#include "PriorityQueue.h"
#include "Tree.h"


class ShortestPath {
public:
    explicit ShortestPath(Graph &g);
    // Find the shortest path between two nodes
    std::list<Node *> path(int source, int destination);

    // Find the distance of the shortest path between two nodes
    double pathLength(int source, int destination);

    // Reset
    void reset();
private:
    Graph & graph;
    PriorityQueue<Node *> openSet = {};
    std::set<Node *> closedSet = {};
    Tree<Node *> pathTree = {};

    // One step of the search
    void onestep();
};


#endif //WEEK3_SHORTESTPATH_H
