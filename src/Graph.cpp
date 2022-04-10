//
// Created by Sadique Sheik on 15.03.22.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

// Default constructor
Graph::Graph() {}

// Build a graph from a given list of nodes
Graph::Graph(vector<Node *> &nodes) : nodes(nodes) {
    // This vector should perhaps be sorted??
    // For the sake of this constructor we assume that the vector is already pre-sorted by node ids.
}

// Build a graph with n nodes
Graph::Graph(int n, bool symmetric): nodes(vector<Node *>(n)), bidirectional(symmetric) {
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


// Add an edge to the graph
void Graph::add(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    // Add the edge to source if it doesn't already exist
    if (! nodeX->adjacent(*nodeY)) {
        nodeX->add(*nodeY);
        // Repeat the same for the other direction
        if (bidirectional) {
            nodeY->add(*nodeX);
        }
    }
}


// Delete an edge between x and y
void Graph::del(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    // If an edge exists, delete it
    if (nodeX->adjacent(*nodeY)){
        nodeX->del(*nodeY);
        if (bidirectional) {
            nodeY->del(*nodeX);
        }
    }
}


// Check if a node x is adjacent to y
bool Graph::adjacent(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    return nodeX->adjacent(*nodeY);
}

// Get a list of all neighbors of a given node
list<Node *> Graph::neighbors(int x) {
    list<Node *> nodes;
    for (auto edge: at(x)->getEdges()){
        nodes.push_back(edge.destination);
    }
    return nodes;
}

// Get the node with a given id
Node * Graph::at(const int index) {
    return nodes.at(index);
}

// Get the node value.
// This method is redundant in this class since the id is the same as the index of an element.
int Graph::getNodeValue(Node& x) {
    return x.getId();
}


// Set the value of a given node.
void Graph::setNodeValue(Node &x, int a) {
    x.setId(a);
}


// Get the value of an edge between x and y
double Graph::getEdgeValue(int x, int y) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    return nodeX->getEdge(*nodeY).length;
}

// Set the value of an edge between x and y
void Graph::setEdgeValue(int x, int y, double v) {
    auto nodeX = at(x);
    auto nodeY = at(y);
    nodeX->getEdge(*nodeY).length = v;
    if (bidirectional){
        nodeY->getEdge(*nodeX).length = v;
    }
}

Graph::Graph(const std::string& filename) {
    string line;
    ifstream graph_data_file(filename);
    std::cout << filename;
    int node_size, source, destination, cost;
    graph_data_file >> node_size;
    // Ideally i would like to call the other constructor here, but not sure how
    nodes = vector<Node *>(node_size);
    for (int i=0; i<nodes.size(); i++){
        // Initialize each node with an id
        nodes.at(i) = new Node(i);
    }
    std::cout << "Graph size of " << node_size << " is being read from file" << endl;
    while (graph_data_file.good()){
        // Read data from each line
        graph_data_file >> source;
        graph_data_file >> destination;
        graph_data_file >> cost;
        // Add corresponding edge to the graph
        add(source, destination);
        setEdgeValue(source, destination, cost);
    }
    graph_data_file.close();
}


