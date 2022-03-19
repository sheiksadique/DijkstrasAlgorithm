//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_PRIORITYQUEUE_H
#define WEEK3_PRIORITYQUEUE_H

#include <list>
#include "QueueElement.h"
using namespace std;

template <typename T>
class PriorityQueue {
public:
    int size();
    bool contains(T item);
    double getPriority(T item);
    void insert(T item, double priority);
    void updatePriority(T item, double priority);
    QueueElement<T> & top();
    QueueElement<T> & pop();

private:
    list<QueueElement<T>> elements; // Pair of elements and their priorities
};



#endif //WEEK3_PRIORITYQUEUE_H
