# Code output
```
No. of edges: 237/1225 = 0.193469
Average path length for a graph of size 50 : 6.19796
Total run-time: 187ms
No. of edges: 485/1225 = 0.395918
Average path length for a graph of size 50 : 4.73141
Total run-time: 391ms
```

# Summary of the exercise and learning

Here I choose to implement edge list version of a graph implementation as this gives me a chance to explore OOP with C++.
In addition, edge list version could be more efficient with low density graphs.
First thing I learned in the process was about friend methods in classes, that are very handy to override operators.
Secondly, I learned that template class definitions cannot be split into a header file and source file. Otherwise the linker fails.

I also learned to time my code using the chrono library.
My PriorityQueue implementation is very inefficient. Ideally I should have used some kind of a tree/heap datastructure but for simplicity I am using a list to store all the elements.
I chose to implement the PriorityQueue using templates as this is a generic class that could be potentially used for other types of data structures unrelated to this assignment.

The ShortestPath class is implemented in a stateful manner such that the graph is retained until the source node changes.
This implementation enables reuse of computations and makes the algorithm particularly efficient to compute distances between all node pairs.

In addition, since the chosen graph is bidirectional, we only need to compute the distance a pair of two nodes x and y without computing the distance between y and x.
This effectively halves the total number of computations required.

This project is complex with several classes and data structures.
In order to test that my implementations are correct during the development phase, I also write a set of test functions that execute smaller parts of code and checks their output agains known/expected outputs.
This helped me immensely in testing and debugging the code.
Another aspect that I learned in the process was error handling with try catch blocks and custom exceptions.
This was also very useful to identify and prevent the code from failing if a pair of nodes in the graph are not connected.


# Code
All of my code is hosted on github at https://github.com/sheiksadique/DijkstrasAlgorithm and is available to review and comment.

Here I will paste just the code from the main file.

```
/*
 * main.cpp
 * Author Sadique Sheik
 * Week 3 assignment. Dijkstra's algorithm to find the shortest path in a graph.
 */
#include <iostream>
#include <random>
#include <chrono>
#include "Graph.h"
#include "ShortestPath.h"
#include "NoPathException.h"

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


void assignment(double density){
    Graph g = genRandomGraph(50, density, 1.0, 10.0);
    int maxEdges = (g.V()*(g.V()-1))/2;
    cout << "No. of edges: " << g.E()  << "/" << maxEdges << " = " << 1.0*g.E()/maxEdges << endl;

    auto start = chrono::high_resolution_clock::now();
    averagePathLength(g);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << "Total run-time: " << duration.count() << "ms" << endl;
}

int main() {
    assignment(0.2);
    assignment(0.4);
    return 0;
}
```
