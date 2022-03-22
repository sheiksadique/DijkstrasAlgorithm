//
// Created by Sadique Sheik on 15.03.22.
//

#include "ShortestPath.h"
#include <iostream>
using namespace std;


ShortestPath::ShortestPath(Graph &g): graph(g) {}



double ShortestPath::pathLength(int source, int destination) {
    auto destinationNode = graph.at(destination);
    double distance = 0;
    auto pathNodes = path(source, destination);
    // Sum up all the lengths of the edges along the shortest path
    for (auto it=pathNodes.begin(); it!=pathNodes.end(); it++){
        auto currentNode = *it;
        // If we are not already at the destination find the distance to the next node.
        if (currentNode != destinationNode) {
            auto nextNode = *next(it);
            Edge e = currentNode->getEdge(*nextNode);
            distance = distance + e.length;
        }
    }
    return distance;
}

list<Node *> ShortestPath::path(int i, int j) {
    auto source = graph.at(i);
    auto destination = graph.at(j);
    // Reset the algorithm
    reset();
    // Add source node to the open set with distance 0
    openSet.insert(source, 0.0, {source});
    //if (source != startingNode){
    //    // Add source node to the open set with distance 0
    //    openSet.insert(source, 0.0, {source});
    //} else {
    //    // If node already in closed set, no need to search

    //}
    while (openSet.size() != 0){
        onestep();
        auto top = openSet.top();
        if (top.data == destination) {
            return top.path; // Shortest path found
        }
    }
    throw std::runtime_error("No path found");
}


void ShortestPath::onestep() {
    // Get the element with the shortest path in the open set
    auto top = openSet.pop();
    auto source = top.data;
    auto startDistance = top.priority;
    auto startPath = top.path;
    // Add the node to the closed set
    closedSet.insert(source);
    cout << "Moving node " << source->getId() << " from openSet to closedSet." << endl;

    // Iterate over neighbors
    for (Edge e: source->getEdges()){
        if (closedSet.find(e.destination) != closedSet.end()){
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
                cout << "Adding node " << e.destination->getId() << " to openSet." << endl;
            }
        }
    }

}

void ShortestPath::reset() {
    openSet = {};
    closedSet.clear();
}
