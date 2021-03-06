//
// Created by Sadique Sheik on 16.03.22.
//

#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "ShortestPath.h"
#include "MinimumSpanningTree.h"

using namespace std;

// Check if a single node can be constructed
void generateSingleNode(){
    Node n {0};
    std::cout << n;
}

// Generate a single edge
void generateSingleEdge(){
    // Note that this method is not complete because the nodes themselves do not have a reference to this edge.
    Node a {0};
    Node b {1};
    Edge e {&a, &b, 5};
    std::cout << e << endl;
}

// Check if two nodes are adjacent to each other
void checkAdjacentNode(){
    Node a {0};
    Node b {1};
    Node c {2};
    a.add(b);
    assert(a.adjacent(b));
    assert(!a.adjacent(c));
}

// Generate a complete graph and test against the total number of edges
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

// Test that edge deletion works as expected
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

// Test shortest path algorithm on a graph with two nodes
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


// Test shortest path algorithm on a graph with 3 nodes
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
    assert(sp.pathLength(1, 2) == 1);
    assert(sp.pathLength(2, 1) == 1);
    assert(sp.pathLength(0, 1) == 1);
    assert(sp.pathLength(1, 0) == 1);
}


void testMstPriorityQueue(){
    Graph g {4};
    MinimumSpanningTree mst {g};

    Edge e1 {g.at(0), g.at(1), 1.0};
    Edge e2 {g.at(0), g.at(1), 3.5};
    Edge e3 {g.at(0), g.at(1), 0.1};

    mst.addPotentialEdge(e1);
    mst.printEdgeList();
    mst.addPotentialEdge(e2);
    mst.printEdgeList();
    mst.addPotentialEdge(e3);
    mst.printEdgeList();

    mst.getNextShortestEdge();
    mst.printEdgeList();
}


// Run all test functions defined above.
int main(){
    /*
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
    */
    testMstPriorityQueue();
}
