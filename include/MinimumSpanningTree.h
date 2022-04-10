//
// Created by Sadique Sheik on 10.04.22.
//

#ifndef WEEK3_MINIMUMSPANNINGTREE_H
#define WEEK3_MINIMUMSPANNINGTREE_H


#include "Graph.h"
#include <vector>
#include <set>

class MinimumSpanningTree {
public:
    explicit MinimumSpanningTree(const Graph &g);

    std::vector<Edge* > compute();
    double getCost() const;

private:
    Graph graph;
    double cost=-1; // Initial value
    std::set<Node* > exploredNodes;
    std::vector<Edge* > potentialEdges; // Sorted list of edges

    void updatePotentialEdges();
    void addPotentialEdge(Edge* edge);
    Edge* getNextShortestEdge();
    bool isExplored(Node &node);
    void addNodeToExplored(Node* node);
};


#endif //WEEK3_MINIMUMSPANNINGTREE_H
