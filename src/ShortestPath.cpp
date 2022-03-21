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
    // initialize pathTree
    pathTree = {source, nullptr, {}};
    // Add source node to the open set with distance 0
    openSet.insert(source, 0.0);
    cout << "Adding node " << source->getId() << " to openSet." << endl;
    while (openSet.size() != 0){
        onestep();
        auto top = openSet.top();
        if (top.data == destination) {
            // Found shortest path
            return pathTree;
        }
    }
    throw std::runtime_error("No path found");
}


void ShortestPath::onestep() {
    cout << "Open set size : " << openSet.size() << ". ClosedSet size: "<< closedSet.size() << endl;
    // Get the element with the shortest path in the open set
    auto top = openSet.pop();
    Node * source = top.data;
    double startDistance = top.priority;

    // Add the node to the closed set
    closedSet.insert(source);
    cout << "Moving node " << source->getId() << " from open set to closed set." << endl;

    // Iterate over neighbors
    for (Edge e: source->getEdges()){
        if (closedSet.find(e.destination) != closedSet.end()){
            // Node already explored. Ignore.
        } else {
            if (openSet.contains(e.destination)) {
                // Check current value and update as required
                if ((e.length+startDistance) < openSet.getPriority(e.destination)) {
                    // New best path
                    openSet.updatePriority(e.destination, e.length + startDistance);
                } else {
                    // Old path was better. Ignore
                }
            } else {
                // If destination node not in the set, add it
                // The length should be sum of current + edge length
                openSet.insert(e.destination, startDistance + e.length);
                cout << "Adding node " << e.destination->getId() << " to openSet." << endl;
            }
        }
    }

}

void ShortestPath::reset() {
    openSet = {};
    closedSet.clear();
}
