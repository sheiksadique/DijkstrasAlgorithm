//
// Created by Sadique Sheik on 10.04.22.
//

#ifndef WEEK3_MINIMUMSPANNINGTREE_H
#define WEEK3_MINIMUMSPANNINGTREE_H


#include "Graph.h"
#include <vector>

class MinimumSpanningTree {
public:
    explicit MinimumSpanningTree(const Graph &g);

    std::vector<Edge> compute();
    double getCost() const;

private:
    Graph g;
    double cost=-1; // Initial value
};


#endif //WEEK3_MINIMUMSPANNINGTREE_H
