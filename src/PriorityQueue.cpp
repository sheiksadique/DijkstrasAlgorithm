//
// Created by Sadique Sheik on 15.03.22.
//

#include "PriorityQueue.h"

template<typename T>
int PriorityQueue<T>::size() {
    return elements.size();
}

template<typename T>
bool PriorityQueue<T>::contains(T item) {
    for (QueueElement<T> elem: elements){
        if (elem == item) return true;
    }
    return false;
}

template<typename T>
double PriorityQueue<T>::getPriority(T item) {
    for (QueueElement<T> elem: elements){
        if (elem == item) return elem.priority;
    }
    // NOTE: If the value hasn't been found, nothing gets returned.
    // Some exception handing would be needed to avoid run time errors.
}

template<typename T>
void PriorityQueue<T>::insert(T item, double priority) {
    for (auto it=elements.begin(); it!=elements.end(); it++){
        // If the new value has higher priority ie smaller value
        if (priority<(*it).priority){
            elements.insert(it, {item, priority});
            return;
        }
    }
    // Reached the end of the list, new element has the least priority
    elements.push_back({item, priority});
}

template<typename T>
void PriorityQueue<T>::updatePriority(T item, double priority) {
    // Erase the element from the queue
    for (auto it=elements.begin(); it!=elements.end(); it++){
        if (it->data==item) {
            elements.erase(it);
            break;
        }
    }
    // Insert element with new priority
    insert(item, priority);
}

template<typename T>
QueueElement<T> &PriorityQueue<T>::top() {
    return elements.front();
}

template<typename T>
QueueElement<T> &PriorityQueue<T>::pop() {
    return elements.pop_front();
}
