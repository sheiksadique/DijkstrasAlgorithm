//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_NODE_H
#define WEEK3_NODE_H

#include <list>
#include <ostream>
#include "Edge.h"

using namespace std;

class Node {
public:
    Node();
    Node(int id);
    Node(int id, list<Edge> &edges);

    int getId() const;
    void setId(int id);
    const list<Edge> &getEdges() const;

    void add(Node& y);
    void del(Node& y);
    bool adjacent(Node& y);

    friend ostream &operator<<(ostream &os, const Node &node);

    // Number of edges of this node
    int E();

private:
    int id;
    list<Edge> edges;
public:
};


#endif //WEEK3_NODE_H
