//
// Created by Sadique Sheik on 15.03.22.
//

#include "Graph.h"

// Default constructor
Graph::Graph() {}

// Build a graph from a given list of nodes
Graph::Graph(vector<Node *> &nodes) : nodes(nodes) {
    // This vector should perhaps be sorted??
    // For the sake of this constructor we assume that the vector is already pre-sorted by node ids.
}

// Build a graph with n nodes
Graph::Graph(int n): nodes(vector<Node *>(n)) {
    for (int i=0; i<nodes.size(); i++){
        // Initialize each node with an id
        nodes.at(i) = new Node(i);
    }
}

// Destructor
Graph::~Graph() {
    nodes.clear();
}

// Return the number of nodes in the graph
int Graph::V() {
    return nodes.size();
}

// Returns the number of edges in the graph
int Graph::E() {
    int sum = 0;
    // Sum over all the edges
    for (auto & node : nodes) {
        sum = sum + node->E();
    }
    // If it is a bidirectional graph, the edges appear twice
    if (bidirectional)
        return sum/2;
    else
        return sum;
}

void Graph::add(Node& x, Node& y) {
    // Add the edge to source
    x.add(y);
    // Repeat the same for the other direction
    if (bidirectional) {
        y.add(x);
    }
}

bool Graph::adjacent(Node x, Node y) {
    return x.adjacent(y);
}

list<Node *> Graph::neighbors(const Node& x) {
    list<Node *> nodes;
    for (auto edge: x.getEdges()){
        nodes.push_back(edge.destination);
    }
    return nodes;
}

Node * Graph::at(const int index) {
    return nodes.at(index);
}

void Graph::del(Node &x, Node &y) {
    x.del(y);
    if (bidirectional) {
        y.del(x);
    }
}

int Graph::get_node_value(Node& x) {
    return x.getId();
}

void Graph::set_node_value(Node &x, int a) {
    x.setId(a);
}

double Graph::get_edge_value(Node& x, Node& y) {
    return x.getEdge(y).length;
}

void Graph::set_edge_value(Node &x, Node &y, double v) {
    x.getEdge(y).length = v;
}


