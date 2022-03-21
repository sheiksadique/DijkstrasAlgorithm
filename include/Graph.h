//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_GRAPH_H
#define WEEK3_GRAPH_H

#include <vector>
#include "Node.h"


class Graph {
public:
    // Constructors
    Graph();
    explicit Graph(int n);
    explicit Graph(std::vector<Node *> &nodes);


    // Destructor
    virtual ~Graph();

    // Returns the number of vertices in the graph
    int V();
    // Returns the number of edges in the graph
    int E();
    // adds to G the edge from x to y, if it is not there.
    void add (int x, int y);
    //removes the edge from x to y, if it is there.
    void del (int x, int y);
    // accessor
    Node * at(const int index);
    // Tests whether there is an edge from node x to node y
    bool adjacent(int x, int y);
    // Lists all nodes y such that there is an edge from x to y
    std::list<Node *> neighbors(int x);
    // returns the value associated with the node x.
    int getNodeValue (Node& x);
    //sets the value associated with the node x to a.
    void setNodeValue(Node& x, int a);
    // returns the value associated to the edge (x,y).
    double getEdgeValue(int x, int y);
    //sets the value associated to the edge (x,y) to v.
    void setEdgeValue (int x, int y, double v);

private:
    std::vector<Node *> nodes;
    bool bidirectional=true;
};


#endif //WEEK3_GRAPH_H
