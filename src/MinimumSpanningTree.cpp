//
// Created by Sadique Sheik on 10.04.22.
//

#include "MinimumSpanningTree.h"
#include <iostream>

MinimumSpanningTree::MinimumSpanningTree(const Graph &g) : g(g) {}

double MinimumSpanningTree::getCost() const {
    if (cost == -1) {
        std::cout << "The value has not yet been computed" << std::endl;
    }
    return cost;
}

std::vector<Edge> MinimumSpanningTree::compute() {
    std::vector<Edge> tree;
    return tree;
}
