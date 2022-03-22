//
// Created by Sadique Sheik on 17.03.22.
//

#ifndef WEEK3_QUEUEELEMENT_H
#define WEEK3_QUEUEELEMENT_H

#include <list>

template <typename T>
class QueueElement {
public:
    T data;
    double priority;
    std::list<T> path;

    bool operator==(const QueueElement &rhs) const {
        return data == rhs.data;
    }

    bool operator!=(const QueueElement &rhs) const {
        return rhs != *this;
    }

    bool operator>(const QueueElement rhs) const {
        // The higher the priority, the smaller the value/distance
        return priority < rhs.priority;
    }
};


#endif //WEEK3_QUEUEELEMENT_H
