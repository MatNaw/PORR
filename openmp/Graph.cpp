#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <iostream>
#include "Graph.h"

//static volatile int counter;

void Graph::addEdge(int vertexA, int vertexB) {
//    int first = std::max(vertexA, vertexB);
//    int second = std::min(vertexA, vertexB);
//    adjacencyMatrix[first - 1][second - 1] = 1;
//    Sleep(1);
//    printf("%d %d\n", vertexA, vertexB);
    adjacencyMatrix_test[vertexA - 1]++;
    adjacencyMatrix_test[vertexB - 1]++;
}

int Graph::getVertexCount() const {
    return vertexCount;
}

void Graph::showFriends() {
//    bool temp = true;
    int counter;
//    #pragma omp parallel
    for (int i = 0; i < getVertexCount(); ++i) {
        counter = adjacencyMatrix_test[i];
//        if(counter < 0) {
//            temp = false;
//        }
        std::cout << i + 1 << " " << counter << std::endl;
//        int counter = 0;

//        for (int j = 0; j < i + 1; ++j) {
//            if (adjacencyMatrix[i][j] == 1) {
//                ++counter;
//            }
//        }
    }
}

void Graph::showFriendsOptimized() {
    #pragma omp parallel for
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;

        #pragma omp parallel for
        for (int j = 0; j < i + 1; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                ++counter;
            }
        }
    }
}
#pragma clang diagnostic pop