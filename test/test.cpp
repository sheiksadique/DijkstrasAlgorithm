//
// Created by Sadique Sheik on 16.03.22.
//

#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;

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
            g.add(i, j);
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
            g.add(i, j);
        }
    }
    cout << "No. of edges: " << g.E() << endl;

    // Delete 1 edge
    g.del(0, 1);

    cout << "No. of edges after deleting: " << g.E() << endl;
}

void testShortestPath2Node(){
    Graph g = Graph(2);
    assert (g.E() == 0);
    g.add(0, 1);
    assert (g.E() == 1);
    g.setEdgeValue(0, 1, 4);

    cout << "Neighbors of 0 " << g.neighbors(0).front()->getId() << endl;
    cout << "Neighbors of 1 " << g.neighbors(1).front()->getId() << endl;
    ShortestPath sp {g};
    cout << "...... 0 to 1...." << endl;
    assert(sp.pathLength(0, 1) == 4);
    cout << ".... 1 to 0 ....." << endl;
    assert(sp.pathLength(1, 0) == 4);
    cout << "............" << endl;
}

void testShortestPath3Node() {
    Graph g = Graph(3);
    g.add(0, 1);
    g.setEdgeValue(0, 1, 1);
    g.add(1, 2);
    g.setEdgeValue(1, 2, 1);
    g.add(0, 2);
    g.setEdgeValue(0, 2, 4);

    ShortestPath sp {g};
    assert(sp.pathLength(0, 2) == 2);
    assert(sp.pathLength(2, 0) == 2);
    cout << "............" << endl;
    assert(sp.pathLength(1, 2) == 1);
    assert(sp.pathLength(2, 1) == 1);
    assert(sp.pathLength(0, 1) == 1);
    assert(sp.pathLength(1, 0) == 1);
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

    testShortestPath2Node();

    testShortestPath3Node();
}
