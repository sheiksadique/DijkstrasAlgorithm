//
// Created by Sadique Sheik on 10.04.22.
//

#ifndef WEEK3_MINIMUMSPANNINGTREE_H
#define WEEK3_MINIMUMSPANNINGTREE_H


#include "Graph.h"
#include <vector>
#include <set>

/*
 * MinimumSpanningTree class
 * Implements the Prim's algorithm as described in the lecture.
 * https://en.wikipedia.org/wiki/Prim%27s_algorithm
 *
 */
class MinimumSpanningTree {
public:
    // Constructor
    explicit MinimumSpanningTree(const Graph &g);

    // Compute the minimum spanning tree for the given graph
    std::vector<Edge> compute();

    // Get the cost of MST
    double getCost() const;

    // Add a potential edge
    void addPotentialEdge(Edge edge);

    // Get the next shortest edge to form the tree
    Edge getNextShortestEdge();

    /*
     * Debug method to print the number of explored nodes and number of potential edges
     */
    void printState();
    // Print all potential edges
    void printEdgeList();

    void reset();
private:
    Graph graph;
    double cost=-1; // Initial value
    std::set<Node* > exploredNodes;
    std::vector<Edge > potentialEdges; // Sorted list of edges

    void updatePotentialEdges();
    bool isExplored(Node &node);
    void addNodeToExplored(Node* node);
};


#endif //WEEK3_MINIMUMSPANNINGTREE_H
