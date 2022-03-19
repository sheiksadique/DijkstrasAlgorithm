//
// Created by Sadique Sheik on 15.03.22.
//

#include "ShortestPath.h"

ShortestPath::ShortestPath(Graph &g): graph(g) {}

double ShortestPath::path_size(Node *source, Node *destination) {
    double distance = 0;
    // Sum up all the lengths of the edges along the shortest path
    for (Edge e: path(source, destination)){
        distance = distance + e.length;
    }
    return distance;
}

list<Edge> ShortestPath::path(Node *source, Node *destination) {
    // Add source node to the open set with distance 0
    openset.insert(source, 0.0);

    while (openset.size() != 0){
        onestep();
        auto top = openset.top();
        if (top.data == destination) {
            // Found shortest path
            break;
        }
    }

    return list<Edge>();
}


void ShortestPath::onestep() {
    // Get the element with the shortest path in the open set
    auto top = openset.pop();
    Node * source = top.data;
    double startDistance = top.priority;

    // Add the node to the closed set
    closedset.insert(source);

    // Iterate over neighbors
    for (Edge e: source->getEdges()){
        if (closedset.find(e.destination) != closedset.end()){
            // Node already explored. Ignore.
        } else {
            if (openset.contains(e.destination)) {
                // Check current value and update as required
                if ((e.length+startDistance) < openset.getPriority(e.destination)) {
                    // New best path
                    openset.updatePriority(e.destination, e.length+startDistance);
                } else {
                    // Old path was better. Ignore
                }
            } else {
                // If destination node not in the set, add it
                // The length should be sum of current + edge length
                openset.insert(e.destination, startDistance+e.length);
            }
        }
    }

}
