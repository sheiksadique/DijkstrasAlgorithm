//
// Created by Sadique Sheik on 16.03.22.
//

#ifndef WEEK3_EDGE_H
#define WEEK3_EDGE_H

#include <ostream>

class Node; // Forward declaration to avoid cyclic dependency

class Edge {
public:
    // Constructors
    Edge();
    Edge(Node *source, Node *destination, double length);

    // String representation
    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);

    // Public class attributes
    // NOTE: Ideally we could add getters and setters.
    // But it seems like an overkill.
    // So I decided to make the attributes public.
    Node * source;
    Node * destination;
    double length;
};


#endif //WEEK3_EDGE_H
