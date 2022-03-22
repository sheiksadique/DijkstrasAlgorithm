#include <iostream>
#include <random>
#include "Graph.h"
#include "ShortestPath.h"

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

int main() {
    Graph g = genRandomGraph(50, 0.1, 1.0, 10.0);
    int maxEdges = (g.V()*(g.V()-1))/2;
    cout << "No. of edges: " << g.E()  << "/" << maxEdges << " = " << 1.0*g.E()/maxEdges << endl;

    ShortestPath sp {g};

    return 0;
}
