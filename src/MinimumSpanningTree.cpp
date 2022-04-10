//
// Created by Sadique Sheik on 10.04.22.
//

#include "MinimumSpanningTree.h"
#include <iostream>

MinimumSpanningTree::MinimumSpanningTree(const Graph &g) : graph(g) {}

double MinimumSpanningTree::getCost() const {
    if (cost == -1) {
        std::cout << "The value has not yet been computed" << std::endl;
    }
    return cost;
}

std::vector<Edge* > MinimumSpanningTree::compute() {
    std::vector<Edge* > tree;

    // Start with a random node (we will start with 0 for simplicity
    auto currentNode = graph.at(0);
    // Add it to the exploredNodes
    addNodeToExplored(currentNode);
    // repeat until all nodes have been explored
    while (exploredNodes.size() != graph.V()) {
        // Find the shortest edge
        Edge* nextEdge = getNextShortestEdge();
        // Add edge to tree
        tree.push_back(nextEdge);
        addNodeToExplored(nextEdge->destination);
        updatePotentialEdges();
    }
    // Update cost
    cost = 0;
    for (auto edge: tree) cost += edge->length;
    return tree;
}


/*
 * Add a node to explored set and correspondingly update the potentialEdges
 */
void MinimumSpanningTree::addNodeToExplored(Node* node) {
    exploredNodes.insert(node);
    // Add potential edges
    for (auto e: node->getEdges()) {
        if (!isExplored(*e.destination))
            addPotentialEdge(&e);
    }
}


/*
 * This method removes all edges to nodes in the exploredNodes
 */
void MinimumSpanningTree::updatePotentialEdges() {
    for (auto it=potentialEdges.begin(); it!=potentialEdges.end(); it++){
        auto potentialEdge = *it;
        auto node = potentialEdge->destination;
        if (isExplored(*node)) {
            potentialEdges.erase(it);
        }
    }
}


/*
 * Check if a node is already explored
 */
bool MinimumSpanningTree::isExplored(Node &node) {
    return exploredNodes.find(&node) != exploredNodes.end();
}
