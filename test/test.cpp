//
// Created by Sadique Sheik on 16.03.22.
//

#include <iostream>
#include "Node.h"
#include "Graph.h"

void generateSingleNode(){
    Node n {0};
    std::cout << n;
}

void generateSingleEdge(){
    // Note that this method is not complete because the nodes themselves do not have a reference to this edge.
    Node a {0};
    Node b {1};
    Edge e {&a, &b, 5};
    std::cout << e << endl;
}


void checkAdjacentNode(){
    Node a {0};
    Node b {1};
    Node c {2};
    a.add(b);
    assert(a.adjacent(b));
    assert(!a.adjacent(c));
}

void generateCompleteGraph(int size){
    Graph g {size}; // Bidirectional graph
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            auto a = g.at(i);
            auto b = g.at(j);
            g.add(*a, *b);
        }
    }

    assert(g.V()==size);
    assert(g.E() == size*(size -1)/2);
    cout << "No. of edges: " << g.E() << endl;
}


void testEdgeDeletion(int size){
    // Generate a complete graph
    Graph g {size}; // Bidirectional graph
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            g.add(*g.at(i), *g.at(j));
        }
    }
    cout << "No. of edges: " << g.E() << endl;

    // Delete 1 edge
    g.del(*g.at(0), *g.at(1));

    cout << "No. of edges after deleting: " << g.E() << endl;


}


int main(){
    std::cout << "Running tests" << std::endl;
    generateSingleNode();
    generateSingleEdge();
    checkAdjacentNode();
    generateCompleteGraph(1);
    generateCompleteGraph(2);
    generateCompleteGraph(10);

    testEdgeDeletion(4);
}
