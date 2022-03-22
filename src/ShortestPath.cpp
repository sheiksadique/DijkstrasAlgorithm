//
// Created by Sadique Sheik on 15.03.22.
//

#include "ShortestPath.h"
#include "NoPathException.h"
#include <iostream>
using namespace std;

/*
 * Constructor
 */
ShortestPath::ShortestPath(Graph &g): graph(g) {}


/*
 * Compute and return the shortest path length between two nodes in a graph.
 */
double ShortestPath::pathLength(int source, int destination) {
    double distance = 0;
    // Find the shortest path
    auto pathNodes = path(source, destination);
    // Sum up all the lengths of the edges along the shortest path
    for (auto it=pathNodes.begin(); it!=pathNodes.end(); it++){
        auto currentNode = *it;
        // If we are not already at the destination find the distance to the next node.
        if (currentNode->getId() != destination) {
            auto nextNode = *next(it);
            // Find the edge between the current node and next
            Edge e = currentNode->getEdge(*nextNode);
            distance = distance + e.length;
        }
    }
    return distance;
}


/*
 * Find the shortest path between two nodes in a graph
 */
list<Node *> ShortestPath::path(int i, int j) {
    auto source = graph.at(i);
    auto destination = graph.at(j);
    // If the source is the same as before, maintain the state of the algorithm
    if (source != startingNode){
        // Reset otherwise
        reset();
        startingNode = source;
        // Add source node to the open set with distance 0
        openSet.insert(source, 0.0, {source});
    }

    /*
     * If the destination is already in the closed set,
     * there is no need to search further!
     * We already have the shortest path
     */
    if (isInClosedSet(j))
        return getFromClosedSet(j).path;

    while (openSet.size() != 0){
        // Check top element
        auto top = openSet.top();
        if (top.data == destination) {
            closedSet.insert(top);
            // cout << "Moving node " << source->getId() << " from openSet to closedSet." << endl;
            return top.path; // Shortest path found
        } else {
            oneStep();
        }
    }
    throw NoPathException {i, j};
}


/*
 * Perform one step of edge search from the highest priority node in the openSet
 */
void ShortestPath::oneStep() {
    // Get the element with the shortest path in the open set
    auto top = openSet.pop();
    auto source = top.data;
    auto startDistance = top.priority;
    auto startPath = top.path;
    // Add the node to the closed set
    closedSet.insert(top);
    // cout << "Moving node " << source->getId() << " from openSet to closedSet." << endl;

    // Iterate over neighbors
    for (Edge e: source->getEdges()){
        if (isInClosedSet(e.destination->getId())){
            // Node already explored. Ignore.
        } else {
            list<Node *> newPath(startPath);
            newPath.push_back(e.destination);
            double newDistance = e.length + startDistance;
            if (openSet.contains(e.destination)) {
                // Check current value and update as required
                if ((e.length+startDistance) < openSet.getPriority(e.destination)) {
                    // New best path
                    openSet.updatePriority(e.destination, newDistance, newPath);
                } else {
                    // Old path was better. Ignore
                }
            } else {
                // If destination node not in the set, add it
                // The length should be sum of current + edge length
                openSet.insert(e.destination, newDistance, newPath);
                // cout << "Adding node " << e.destination->getId() << " to openSet." << endl;
            }
        }
    }

}

/*
 * Reset the state of the algorithm
 */
void ShortestPath::reset() {
    startingNode = nullptr;
    openSet = {};
    closedSet.clear();
}


/*
 * Check if a given node is in the closed set
 */
bool ShortestPath::isInClosedSet(const int nodeIdx) {
    for (const auto & it : closedSet){
        if (it.data == graph.at(nodeIdx)) return true;
    }
    return false;
}


/*
 * Get a node from the closedSet
 */
const QueueElement<Node *> &ShortestPath::getFromClosedSet(int nodeIdx) {
    for (const auto & it : closedSet){
        if (it.data == graph.at(nodeIdx)) return it;
    }
    throw std::out_of_range("Element not in closed set.");
}
