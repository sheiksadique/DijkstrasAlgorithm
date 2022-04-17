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


void printPath(list<Node *> path) {
    cout << "Path found: length: " << path.size() << " ";
    for (auto n: path) cout << " -> " << n->getId();
    cout << endl;
}


/*
 * Function generates a random graph of a given size and density.
 * The distances are randomly picked within the range (dmin, dmax)
 */
Graph genRandomGraph(int size, double density, double dmin, double dmax){
    // Initialize a graph
    Graph g {size};
    // Setup random number distributions
    std::random_device rd;
    std::mt19937 engine(rd());
    auto prob_distribution = std::uniform_real_distribution<double>{0, 1};
    auto distance_distribution = std::uniform_real_distribution<double>{dmin, dmax};

    // Iterate over all nodes and generate edges
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            // Generate edge probabilistically
            if (prob_distribution(engine)<density){
                g.add(i, j);
                // Set random weight to the edge
                g.setEdgeValue(i, j, distance_distribution(engine));
            }
        }
    }
    return g;
}

/*
 * Compute average path between any two nodes in a graph
 * excluding self connection.
 */
double averagePathLength(Graph & g){
    double sum=0, length;
    int count = 0;
    ShortestPath sp {g};
    /*
     * Since the graph is bidirectional,
     * it is sufficient to loop over half the matrix
     */
    for(int i=0;i<g.V()-1;i++)
        for (int j=i+1;j<g.V();j++){
            try {
                length = sp.pathLength(i, j);
                // Aggregate
                count++;
                sum = sum + length;
            } catch (NoPathException &e) {
                // If  no path was found, exclude it from mean calculation
                cout << "No path found between " << e.src << "and " << e.dst << endl;
            }
        }
    cout << "Average path length for a graph of size " << g.V() << " : " << sum/count << endl;
    return sum/count;

}


void assignmentWeek2(double density){
    Graph g = genRandomGraph(50, density, 1.0, 10.0);
    int maxEdges = (g.V()*(g.V()-1))/2;
    cout << "No. of edges: " << g.E()  << "/" << maxEdges << " = " << 1.0*g.E()/maxEdges << endl;

    auto start = chrono::high_resolution_clock::now();
    averagePathLength(g);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << "Total run-time: " << duration.count() << "ms" << endl;
}


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
    // Assignment week 2
    // assignmentWeek2(0.2);
    // assignmentWeek2(0.4);
    assignmentWeek4();
    return 0;
}
