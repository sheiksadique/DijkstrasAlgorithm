# MinimumSpanningTree implementation: Prim's algorithm


I implemented the Prim's algorithm for this assignment.

The MinimumSpanningTree class holds two important internal data structures:
- a set to store all the explored nodes.
- a vector/priority queue to store all potential edges thus far.

For the priority queue, I simply use a sorted vector for ease of implementation.
Ideally some efficient data structure such as a tree could have been used.

The output of this program on the provided graph file is as shown below.

```
../data/Homework3_SampleTestData_mst_data.txtGraph size of 20 is being read from file
The graph has 20 nodes
Average path length for a graph of size 20 : 7.81053
The length of MST is 19
It should ideally be 19
The minimum spanning tree is : 
Edge: 0 --> 2 length: 2
Edge: 2 --> 9 length: 1
Edge: 9 --> 13 length: 3
Edge: 9 --> 12 length: 3
Edge: 12 --> 17 length: 1
Edge: 17 --> 1 length: 1
Edge: 1 --> 6 length: 1
Edge: 6 --> 5 length: 1
Edge: 5 --> 18 length: 1
Edge: 18 --> 14 length: 1
Edge: 14 --> 11 length: 1
Edge: 12 --> 3 length: 1
Edge: 5 --> 16 length: 2
Edge: 16 --> 10 length: 3
Edge: 10 --> 15 length: 2
Edge: 15 --> 19 length: 2
Edge: 15 --> 4 length: 2
Edge: 4 --> 8 length: 1
Edge: 4 --> 7 length: 1
The MST cost for the given graph is 30

Process finished with exit code 0
```

All the source code for this assignment is developed on top of the data structures from the previous assignment and can be found on the github page:
https://github.com/sheiksadique/DijkstrasAlgorithm

I am only adding the main file and the MinimumSpanningTree class header for brevity in this text file.

```c++
// main.cpp
/*
 * Author: Sadique Sheik
 * Week 3 assignment. Dijkstra's algorithm to find the shortest path in a graph.
 */

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "Graph.h"
#include "ShortestPath.h"
#include "NoPathException.h"
#include "MinimumSpanningTree.h"

using namespace std;


void assignmentWeek4() {
    // Load the graph from file
    Graph g {"../data/Homework3_SampleTestData_mst_data.txt"};
    cout << "The graph has " << g.V() << " nodes" << endl;
    averagePathLength(g);
    
    // Compute the minimum spanning tree
    MinimumSpanningTree mst {g};
    auto edges = mst.compute();
    double cost = mst.getCost();
    
    // Check that the length of MST == (V -1)
    cout << "The length of MST is " << edges.size() << endl;
    cout << "It should ideally be " << g.V() - 1 << endl;
    
    cout << "The minimum spanning tree is : " << endl;
    for (auto e: edges) {
        cout << e << endl;
    }

    cout << "The MST cost for the given graph is " << cost << endl;
}


int main() {
    return 0;
}
```

```c++
// MinimumSpanningTree.h
// Created by Sadique Sheik on 10.04.22.
//

#ifndef WEEK3_MINIMUMSPANNINGTREE_H
#define WEEK3_MINIMUMSPANNINGTREE_H


#include "Graph.h"
#include <vector>
#include <set>

/*
 * MinimumSpanningTree class
 * Implements the Prim's algorithm as described in the lecture.
 * https://en.wikipedia.org/wiki/Prim%27s_algorithm
 *
 */
class MinimumSpanningTree {
public:
    // Constructor
    explicit MinimumSpanningTree(const Graph &g);

    // Compute the minimum spanning tree for the given graph
    std::vector<Edge> compute();

    // Get the cost of MST
    double getCost() const;

    // Add a potential edge
    void addPotentialEdge(Edge edge);

    // Get the next shortest edge to form the tree
    Edge getNextShortestEdge();

    /*
     * Debug method to print the number of explored nodes and number of potential edges
     */
    void printState();
    // Print all potential edges
    void printEdgeList();

    void reset();
private:
    Graph graph;
    double cost=-1; // Initial value
    std::set<Node* > exploredNodes;
    std::vector<Edge > potentialEdges; // Sorted list of edges

    void updatePotentialEdges();
    bool isExplored(Node &node);
    void addNodeToExplored(Node* node);
};


#endif //WEEK3_MINIMUMSPANNINGTREE_H
```
