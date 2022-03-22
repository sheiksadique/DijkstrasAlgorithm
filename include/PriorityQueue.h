//
// Created by Sadique Sheik on 15.03.22.
//

#ifndef WEEK3_PRIORITYQUEUE_H
#define WEEK3_PRIORITYQUEUE_H

#include <list>
#include "QueueElement.h"

template <typename T>
class PriorityQueue {
public:
    int size();
    bool contains(T item);
    double getPriority(T item);
    void insert(T item, double priority, std::list<T> path);
    void updatePriority(T item, double priority, std::list<T> path);
    QueueElement<T> & top();
    QueueElement<T> pop();

private:
    std::list<QueueElement<T>> elements; // Pair of elements and their priorities
};


template<typename T>
int PriorityQueue<T>::size() {
    return elements.size();
}

template<typename T>
bool PriorityQueue<T>::contains(T item) {
    for (QueueElement<T> elem: elements){
        if (elem.data == item) return true;
    }
    return false;
}

template<typename T>
double PriorityQueue<T>::getPriority(T item) {
    for (QueueElement<T> elem: elements){
        if (elem.data == item) return elem.priority;
    }
    // NOTE: If the value hasn't been found, nothing gets returned.
    // Some exception handing would be needed to avoid run time errors.
    throw std::runtime_error("Item not found");
}

template<typename T>
void PriorityQueue<T>::insert(T item, double priority, std::list<T> path) {
    for (auto it=elements.begin(); it!=elements.end(); it++){
        // If the new value has higher priority ie smaller value
        if (priority<(*it).priority){
            elements.insert(it, {item, priority, path});
            return;
        }
    }
    // Reached the end of the list, new element has the least priority
    elements.push_back({item, priority, path});
}

template<typename T>
void PriorityQueue<T>::updatePriority(T item, double priority, std::list<T> path) {
    // Erase the element from the queue
    for (auto it=elements.begin(); it!=elements.end(); it++){
        if (it->data==item) {
            elements.erase(it);
            break;
        }
    }
    // Insert element with new priority
    insert(item, priority, path);
}

template<typename T>
QueueElement<T> &PriorityQueue<T>::top() {
    if (elements.empty()) throw std::out_of_range("top: Priority queue is empty!");
    return elements.front();
}

template<typename T>
QueueElement<T> PriorityQueue<T>::pop() {
    if (elements.empty()) throw std::out_of_range("pop: Priority queue is empty!");
    QueueElement<T> topElem = elements.front();
    elements.pop_front();
    return topElem;
}

#endif //WEEK3_PRIORITYQUEUE_H
