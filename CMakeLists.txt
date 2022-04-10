cmake_minimum_required(VERSION 3.21)
project(Week3)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
add_executable(Week3 src/main.cpp src/Graph.cpp src/ShortestPath.cpp src/Node.cpp src/Edge.cpp include/NoPathException.h src/MinimumSpanningTree.cpp include/MinimumSpanningTree.h)

add_executable(test test/test.cpp src/Graph.cpp src/ShortestPath.cpp src/Node.cpp src/Edge.cpp include/NoPathException.h src/MinimumSpanningTree.cpp include/MinimumSpanningTree.h)
