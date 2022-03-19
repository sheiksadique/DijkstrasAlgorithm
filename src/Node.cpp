//
// Created by Sadique Sheik on 15.03.22.
//

#include "Node.h"
using namespace std;

int Node::getId() const {
    return id;
}

void Node::setId(int id) {
    Node::id = id;
}

int Node::E() {
    return edges.size();
}

Node::Node(): id(-1) {}
Node::Node(int id) : id(id) {}
Node::Node(int id, list<Edge> &edges) : id(id), edges(edges) {}

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

bool Node::adjacent(Node &y) {
    // Iterate over all edges of a node
    for (auto edge: edges) {
        if (edge.destination == &y)
            return true;
    }
    return false;
}

const list<Edge> &Node::getEdges() const {
    return edges;
}

Edge &Node::getEdge(Node &y) {
    for (auto & edge : edges){
        if (edge.destination == &y) return edge;
    }
}


