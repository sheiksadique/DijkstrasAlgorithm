//
// Created by Sadique Sheik on 16.03.22.
//

#ifndef WEEK3_EDGE_H
#define WEEK3_EDGE_H

#include <ostream>

class Node; // Forward declaration to avoid cyclic dependency

class Edge {
public:
    Edge();

    Edge(Node *source, Node *destination, double length);

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);

    Node * source;
    Node * destination;
    double length;
};


#endif //WEEK3_EDGE_H
