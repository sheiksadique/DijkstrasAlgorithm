//
// Created by Sadique Sheik on 15.03.22.
//

#include "Graph.h"
using namespace std;

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

void Graph::add(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    // Add the edge to source
    nodeX->add(*nodeY);
    // Repeat the same for the other direction
    if (bidirectional) {
        nodeY->add(*nodeX);
    }
}

void Graph::del(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    nodeX->del(*nodeY);
    if (bidirectional) {
        nodeY->del(*nodeX);
    }
}

bool Graph::adjacent(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    return nodeX->adjacent(*nodeY);
}

list<Node *> Graph::neighbors(int x) {
    list<Node *> nodes;
    for (auto edge: at(x)->getEdges()){
        nodes.push_back(edge.destination);
    }
    return nodes;
}

Node * Graph::at(const int index) {
    return nodes.at(index);
}


int Graph::getNodeValue(Node& x) {
    return x.getId();
}

void Graph::setNodeValue(Node &x, int a) {
    x.setId(a);
}

double Graph::getEdgeValue(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    return nodeX->getEdge(*nodeY).length;
}

void Graph::setEdgeValue(int x, int y, double v) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    nodeX->getEdge(*nodeY).length = v;
    if (bidirectional){
        nodeY->getEdge(*nodeX).length = v;
    }
}


