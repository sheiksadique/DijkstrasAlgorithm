//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_NODE_H
#define WEEK3_NODE_H

#include <list>
#include <ostream>
#include "Edge.h"


class Node {
public:
    // Constructors
    Node();
    Node(int id);
    Node(int id, std::list<Edge> &edges);

    // Accessors for value of a Node
    int getId() const;
    void setId(int id);

    // Get the list of all Edges of this Node
    const std::list<Edge> &getEdges() const;

    // Add an edge
    void add(Node& y);
    // Delete an edge
    void del(Node& y);
    // Check if a node is adjacent to this Node
    bool adjacent(Node& y);
    // Get the edge between this and a given Node.
    Edge & getEdge(Node& y);

    // String representation of the object
    friend std::ostream &operator<<(std::ostream &os, const Node &node);

    // Number of edges of this node
    int E();

private:
    int id;
    std::list<Edge> edges;
public:
};


#endif //WEEK3_NODE_H
