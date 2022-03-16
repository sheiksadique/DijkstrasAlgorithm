//
// Created by Sadique Sheik on 16.03.22.
//

#include "Edge.h"
#include "Node.h"

Edge::Edge() {}

Edge::Edge(Node *source, Node *destination, double length) : source(source), destination(destination), length(length) {}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << "Edge: " << edge.source->getId() << " --> " << edge.destination->getId() << " length: " << edge.length;
    return os;
}
