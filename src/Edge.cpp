//
// Created by Sadique Sheik on 16.03.22.
//

#include "Edge.h"
#include "Node.h"

// Default constructor
Edge::Edge() {}

// Constructor
Edge::Edge(Node *source, Node *destination, double length) : source(source), destination(destination), length(length) {}

// String representation of an edge
std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << "Edge: " << edge.source->getId() << " --> " << edge.destination->getId() << " length: " << edge.length;
    return os;
}
