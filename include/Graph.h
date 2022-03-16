//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_GRAPH_H
#define WEEK3_GRAPH_H

#include <vector>
#include "Node.h"

using namespace std;

class Graph {
public:
    // Constructors
    Graph();
    explicit Graph(int n);
    explicit Graph(vector<Node *> &nodes);


    // Destructor
    virtual ~Graph();

    // Returns the number of vertices in the graph
    int V();
    // Returns the number of edges in the graph
    int E();
    // accessor
    Node * at(const int index);
    // Tests whether there is an edge from node x to node y
    bool adjacent(Node x, Node y);
    // Lists all nodes y such that there is an edge from x to y
    list<Node *> neighbors(const Node& x);
    // adds to G the edge from x to y, if it is not there.
    void add (Node& x, Node& y);
    //removes the edge from x to y, if it is there.
    void del (Node& x, Node& y);
    // returns the value associated with the node x.
    int get_node_value (Node x);
    //sets the value associated with the node x to a.
    void set_node_value(Node x, int a);
    // returns the value associated to the edge (x,y).
    double get_edge_value(Node x, Node y);
    //sets the value associated to the edge (x,y) to v.
    void set_edge_value (Node x, Node y, double v);

private:
    vector<Node *> nodes;
    bool bidirectional=true;
};


#endif //WEEK3_GRAPH_H
