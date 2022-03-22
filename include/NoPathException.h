//
// Created by Sadique Sheik on 22.03.22.
//

#ifndef WEEK3_NOPATHEXCEPTION_H
#define WEEK3_NOPATHEXCEPTION_H

#include <exception>
#include <sstream>

/*
 * Custom exception to identify when the graph is not connected.
 */
class NoPathException : public std::exception {
public:
    const char * what() const noexcept override {
        return "No path found";
    }

    NoPathException(int src, int dst) : src(src), dst(dst) {}
    int src; // Source
    int dst; // Destination
};


#endif //WEEK3_NOPATHEXCEPTION_H
