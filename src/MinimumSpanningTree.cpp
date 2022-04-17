//
// Created by Sadique Sheik on 10.04.22.
//

#include "MinimumSpanningTree.h"
#include <iostream>

MinimumSpanningTree::MinimumSpanningTree(const Graph &g) : graph(g) {
    reset();
}

double MinimumSpanningTree::getCost() const {
    if (cost == -1) {
        std::cout << "The value has not yet been computed" << std::endl;
    }
    return cost;
}

std::vector<Edge> MinimumSpanningTree::compute() {
    std::vector<Edge> tree;

    // Start with a random node (we will start with 0 for simplicity
    auto currentNode = graph.at(0);
    // Add it to the exploredNodes
    addNodeToExplored(currentNode);
    // repeat until all nodes have been explored
    while (exploredNodes.size() != graph.V()) {
        // Find the shortest edge
        Edge nextEdge = getNextShortestEdge();
        // Add edge to tree
        tree.push_back(nextEdge);
        addNodeToExplored(nextEdge.destination);
        updatePotentialEdges();
    }
    // Update cost
    cost = 0;
    for (auto edge: tree) cost += edge.length;
    return tree;
}


/*
 * Add a node to explored set and correspondingly update the potentialEdges
 */
void MinimumSpanningTree::addNodeToExplored(Node* node) {
    exploredNodes.insert(node);
    // Add potential edges
    for (auto e: node->getEdges()) {
        if (!isExplored(*(e.destination))) {
            addPotentialEdge(e);
        }
    }
}


/*
 * This method removes all edges to nodes in the exploredNodes
 */
void MinimumSpanningTree::updatePotentialEdges() {
    std::vector<Edge> newPotentialEdges {};
    for (auto edge : potentialEdges){
        auto node = edge.destination;
        if (!isExplored(*node)) {
            //potentialEdges.erase(it);
            newPotentialEdges.push_back(edge);
        }
    }
    potentialEdges = newPotentialEdges;
}


/*
 * Check if a node is already explored
 */
bool MinimumSpanningTree::isExplored(Node &node) {
    return exploredNodes.find(&node) != exploredNodes.end();
}


/*
 * Add a potential edge to the sorted list potentialEdges
 */
void MinimumSpanningTree::addPotentialEdge(Edge edge) {
    for (auto it=potentialEdges.begin(); it!=potentialEdges.end(); it++) {
        if (edge.length <= (*it).length) {
            potentialEdges.insert(it, edge);
            return;
        }
    }
    // If the length of the edge is longer than all others, inset at the end of the list.
    potentialEdges.push_back(edge);
}


/*
 * Convenience/debugging method to print all the edge lengths in potentialEdges
 */
void MinimumSpanningTree::printEdgeList() {
    for (auto e: potentialEdges) {
        std::cout << e << ";";
    }
    std::cout << std::endl;
}


/*
 * Get the next shortest edge
 */
Edge MinimumSpanningTree::getNextShortestEdge() {
    if (!potentialEdges.empty()) {
        auto head = potentialEdges.front();
        potentialEdges.erase(potentialEdges.begin());
        return head;
    } else {
        throw std::runtime_error("No potential edges found");
    }
}


/*
 * Reset the internal variables of MST
 */
void MinimumSpanningTree::reset() {
    cost = -1;
    exploredNodes = {};
    potentialEdges = {};
}

void MinimumSpanningTree::printState() {
    std::cout << "Num. explored nodes: " << exploredNodes.size();
    std::cout << " Num. potential edges: " << potentialEdges.size() << std::endl;
}
