//
// Created by Sadique Sheik on 15.03.22.
//

#include "Node.h"
using namespace std;

// Getter method for id of a node
int Node::getId() const {
    return id;
}

// Setter for id of a node
void Node::setId(int id) {
    Node::id = id;
}

// Return the number of edges of this node
int Node::E() {
    return edges.size();
}

// Default constructor
Node::Node(): id(-1) {}

// Constructors
Node::Node(int id) : id(id) {}
Node::Node(int id, list<Edge> &edges) : id(id), edges(edges) {}

// String representation
ostream &operator<<(ostream &os, const Node &node) {
    //os << "id: " << node.id << " edges: " << node.edges;
    os << "Node: id: " << node.id << endl;
    return os;
}

/*
 * Append an edge to a node
 */
void Node::add(Node &y) {
    Edge edge {this, &y, 0};
    edges.push_back(edge);
}

/*
 * Delete an edge if it exists
 */
void Node::del(Node &y) {
    if (adjacent(y)){
        // Find the edge to y
        for (auto it = edges.begin(); it!=edges.end(); it++){
            if ((*it).destination == &y) {
                // Delete the edge
                edges.erase(it);
                break;
            }
        }
    }
}


// Checks if this node has an edge to a given node
bool Node::adjacent(Node &y) {
    // Iterate over all edges of a node
    for (auto edge: edges) {
        if (edge.destination == &y)
            return true;
    }
    return false;
}


// Getter for edges of a node
const list<Edge> &Node::getEdges() const {
    return edges;
}

// Get the edge to a given node from this node.
Edge &Node::getEdge(Node &y) {
    for (auto & edge : edges){
        if (edge.destination == &y) return edge;
    }
    throw runtime_error("No edge to specified destination was found");
}


