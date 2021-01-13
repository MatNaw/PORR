#include <iostream>
#include <algorithm>
#include "Graph.h"

void Graph::addEdge(int vertexA, int vertexB) {
    int first = std::max(vertexA, vertexB);
    int second = std::min(vertexA, vertexB);
    adjacencyMatrix[first - 1][second - 1] = 1;
//    adjacencyMatrixStdMap[vertexA - 1]++;
//    adjacencyMatrixStdMap[vertexB - 1]++;
}

int Graph::getVertexCount() const {
    return vertexCount;
}

void Graph::showFriends() {
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;

        for (int j = 0; j < i + 1; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                ++counter;
            }
        }
    }
}

void Graph::showFriendsStdMap() {
//    int counter;
//    for (int i = 0; i < getVertexCount(); ++i) {
//        counter = adjacencyMatrixStdMap[i];
//        std::cout << i + 1 << " " << counter << std::endl;
//    }
}

void Graph::showFriendsOptimized(int threadsNumber) {
    #pragma omp parallel for num_threads(threadsNumber)
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;

        for (int j = 0; j < i + 1; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                ++counter;
            }
        }
    }
}