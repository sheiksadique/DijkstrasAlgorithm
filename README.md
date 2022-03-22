Context
=======

This is an assignment project from Coursera C++ course.
This repository implements a graph data structure along with some accompanying classes.

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

All of my code is hosted on github at https://github.com/sheiksadique/DijkstrasAlgorithm and is available to review and comment.

Below is the assignment text from the course.

Dijkstra's Algorithm
====================

Graph algorithms and graph representation are a critical tool in CS. We want to create a graph as an ADT (Abstract Data Type) using C++ classes. The basic problem will be to write Dijkstra’s algorithm as a class member function (method in OO speak). You should already know Dijkstra’s algorithm for the shortest path problem from prior experience, but it will be reviewed in class. It is the basis for many route calculations and optimizations programs.

There are 2 basic implementations used for graphs – one is edge lists, and the other is connectivity matrices. You can decide which to use, but comment on your choice.

Basic problem:  
--------------

Write a set of constructors for declaring and initializing a graph. An edge will have a positive cost that is its distance. Have a procedure that produces a randomly generated set of edges with positive distances.  Assume the graphs are undirected. The random graph procedure should have edge density as a parameter and distance range as a parameter. So a graph whose density is 0.1 would have 10% of its edges picked at random and its edge distance would be selected at random from the distance range. The procedure should run through all possible undirected edges, say (i,j) and place the edge in the graph if a random probability calculation is less than the density. Compute for a set of randomly generated graphs an average shortest path.

Turn in:  
--------

Printout of program, 200 words on what you learned, and output showing the average path length calculation. Use densities: 20% and 40% on a graph of 50 nodes with a distance range of 1.0 to 10.0.   To get an average path length, compute the 49 paths:

1 to 2, 1 to 3, 1 to 4, …, 1 to 50.

[In an instance where there is no path between 1 and n, omit that value from the average. This should be very rare for the chosen density and size in this homework.]

Keep in mind: good style – choice of identifiers, short functions, good documentation, correctness and efficiency. Cite any references in creating this program.

Tips:  Hand-simulate your algorithm on a small graph.

Grading:

Submit the program for peer grading.

> Nota Bene:  Keep in mind that there is a wide array of backgrounds in students taking this course. From this perspective the student who is the intended target has a C background and some computer science. At this point in the class it is not expected that the student know the detailed uses of STL and iterator classes. When peer grading be generous, and read the 200 word explanation. It is certainly okay for an experienced C++ programmer to use the most advanced elements of the libraries and the language if properly explained in her code. Conversely, it is also okay for the beginner to use a much simpler approach.  Problem 3 will continue with graph algorithms and will allow participants to program in a more advanced and richer style.

Reference Abstractions:  
-----------------------

Implementing Dijkstra’s algorithm requires thinking about at least three basic abstractions: 

- Graph (G = (V, E), 
- PriorityQueue, and 
- ShortestPath algorithm.  

Additionally, deciding on a scheme for naming vertices (V) is an important first step in implementation design. By convention, vertices are generally mapped onto the set of Integers in the range from 0 : |V| -1.  This provides an effective Key into sequential containers (like ARRAY) to access node records in constant time - Θ(1). Also, in models where node names are not represented with integers, the use of a symbol table could be used to provide a 1-to-1 mapping to associate V arbitrary names with V integers in the proper range.

A potential partial interface definition for a Graph could be:

Class Graph:
------------

V (G): returns the number of vertices in the graph

E (G): returns the number of edges in the graph

adjacent (G, x, y): tests whether there is an edge from node x to node y.

neighbors (G, x): lists all nodes y such that there is an edge from x to y.

add (G, x, y): adds to G the edge from x to y, if it is not there.

delete (G, x, y): removes the edge from x to y, if it is there.

getNodeValue (G, x): returns the value associated with the node x.

setNodeValue( G, x, a): sets the value associated with the node x to a.

getEdgeValue( G, x, y): returns the value associated to the edge (x,y).

setEdgeValue (G, x, y, v): sets the value associated to the edge (x,y) to v.

One important consideration for the Graph class is how to represent the graph as a member ADT. Two basic implementations are generally considered: adjacency list and adjacency matrix depending on the relative edge density. For sparse graphs, the list approach is typically more efficient, but for dense graphs, the matrix approach can be more efficient (reference an Algorithm’s source for space and time analysis). Note in some cases such as add(G, x, y) you may also want to have the edge carry along its cost. Another approach could be to use (x, y) to index a cost stored in an associated array or map.

The value of the PriorityQueue is to always have access to the node with the next shortest link in the shortest path calculation at the top of the queue. A typically implementation is a minHeap:

Class PriorityQueue
-------------------

chgPrioirity(PQ, priority): changes the priority (node value) of queue element.

minPrioirty(PQ): removes the top element of the queue.

contains(PQ, queue_element): does the queue contain queue_element.

Insert(PQ, queue_element): insert queue_element into queue

top(PQ):returns the top element of the queue.

size(PQ): return the number of queue_elements.

Finally, the class: ShortestPathAlgo implements the mechanics of Dijkstra’s algorithm. Besides having member fields (has a relationship) of Graph and Priority Queue, an additional ADT maybe required to maintain the parent relationship of the shortest path.

Class ShortestPath
------------------

vertices(List): list of vertices in G(V,E).

path(u, w): find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.

pathLength(u, w): return the path cost associated with the shortest path.

The class implementing your Monte Carlo simulation is the workflow manager for this assignment, but other helper classes may be necessary depending on your particular implementation

Notes and Reminders:
--------------------

Write an appropriate set of constructors for each of your classes ensuring proper initialization – especially think about the process for declaring and initializing a graph.

In this implementation, assume that an edge will have a positive cost function like distance (no negative edge cost).

Assume the graph edges (E)  are undirected.

Ensure that your ADTs support a graph of at least size 50.

The random graph procedure should have edge density as a parameter and distance range as a parameter.

Random graph generator should generate a sufficient set of edges to satisfy the edge density parameter, and each edge should be assigned a randomly generated cost based on the distance range parameter.

So a graph whose density is 0.1 would have 10% of its edges picked at random and its edge distance would be selected at random from the distance range.

Compute for a set of randomly generated graphs an average shortest path.

URLs

http://en.wikipedia.org/wiki/Dijkstra's_algorithm