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
