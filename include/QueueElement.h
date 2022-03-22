/*
 * Created by Sadique Sheik on 17.03.22.
 * This template class is meant as a data structure
 * holding the shortest known path from a source.
 *
 * I use a template class to extend its usability to other unforeseen use cases.
*/

#ifndef WEEK3_QUEUEELEMENT_H
#define WEEK3_QUEUEELEMENT_H

#include <list>

template <typename T>
class QueueElement {
public:
    T data;
    double priority;
    std::list<T> path;

    // Equality operator
    bool operator==(const QueueElement &rhs) const {
        return data == rhs.data;
    }

    // Not equal operator
    bool operator!=(const QueueElement &rhs) const {
        return rhs != *this;
    }

    // Greater than operator
    bool operator>(const QueueElement rhs) const {
        // The higher the priority, the smaller the value/distance
        return priority < rhs.priority;
    }

    // Less than operator
    bool operator<(const QueueElement rhs) const {
        // The higher the priority, the smaller the value/distance
        return priority > rhs.priority;
    }
};


#endif //WEEK3_QUEUEELEMENT_H
