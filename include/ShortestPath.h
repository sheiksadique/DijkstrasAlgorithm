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
    // Constructor
    explicit ShortestPath(Graph &g);

    // Find the shortest path between two nodes
    std::list<Node *> path(int source, int destination);

    // Find the distance of the shortest path between two nodes
    double pathLength(int source, int destination);

    bool isInClosedSet(int source);

    // Reset the state of the algorithm
    void reset();
private:
    Graph & graph;
    PriorityQueue<Node *> openSet = {};
    std::set<QueueElement<Node *>> closedSet = {};
    Node * startingNode;

    // Check if a given node is in the closed set
    const QueueElement<Node *> & getFromClosedSet(int nodeIdx);

    // Perform one step of edge search from the highest priority node in the openSet
    void oneStep();
};


#endif //WEEK3_SHORTESTPATH_H
