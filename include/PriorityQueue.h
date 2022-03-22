/*
 * Created by Sadique Sheik on 15.03.22.
 *
 * This is an inefficient implementation of PriorityQueue using lists.
 * This was done purely to save some implementation time.
 *
 * In principle a heap data structure should have been used to represent a priority queue.
 */

#ifndef WEEK3_PRIORITYQUEUE_H
#define WEEK3_PRIORITYQUEUE_H

#include <list>
#include "QueueElement.h"

template <typename T>
class PriorityQueue {
public:
    // Current size of the queue
    int size();
    // Check if a value is present in the queue
    bool contains(T item);
    // Check the priority of an element
    double getPriority(T item);
    // Insert an element in the queue
    void insert(T item, double priority, std::list<T> path);
    // Update the priority of an element in the queue
    void updatePriority(T item, double priority, std::list<T> path);
    // Return the element with the highest priority
    QueueElement<T> & top();
    // Remove the highest priority element from the queue.
    QueueElement<T> pop();

private:
    std::list<QueueElement<T>> elements; // Pair of elements and their priorities
};


// Current size of the queue
template<typename T>
int PriorityQueue<T>::size() {
    return elements.size();
}

// Check if a value is present in the queue
template<typename T>
bool PriorityQueue<T>::contains(T item) {
    for (QueueElement<T> elem: elements){
        if (elem.data == item) return true;
    }
    return false;
}


// Check the priority of an element
template<typename T>
double PriorityQueue<T>::getPriority(T item) {
    for (QueueElement<T> elem: elements){
        if (elem.data == item) return elem.priority;
    }
    // NOTE: If the value hasn't been found, nothing gets returned.
    // Some exception handing would be needed to avoid run time errors.
    throw std::runtime_error("Item not found");
}


// Insert an element in the queue
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


// Update the priority of an element in the queue
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


// Return the element with the highest priority
template<typename T>
QueueElement<T> &PriorityQueue<T>::top() {
    if (elements.empty()) throw std::out_of_range("top: Priority queue is empty!");
    return elements.front();
}

// Remove the highest priority element from the queue.
template<typename T>
QueueElement<T> PriorityQueue<T>::pop() {
    if (elements.empty()) throw std::out_of_range("pop: Priority queue is empty!");
    QueueElement<T> topElem = elements.front();
    elements.pop_front();
    return topElem;
}

#endif //WEEK3_PRIORITYQUEUE_H
