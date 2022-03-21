//
// Created by Sadique Sheik on 21.03.22.
//

#ifndef WEEK3_TREE_H
#define WEEK3_TREE_H

#include <list>

template <typename T>
class Tree {
public:
    Tree();
    Tree(T data, Tree *root, const std::list<Tree<T> *> &branches) : data(data), root(root), branches(branches) {}
private:
    T data;
    Tree * root = nullptr;
    std::list<Tree<T> *> branches = {};
};

template<typename T>
Tree<T>::Tree() {

}


#endif //WEEK3_TREE_H
