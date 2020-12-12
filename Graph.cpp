#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <iostream>
#include <algorithm>
#include "Graph.h"

void Graph::addEdge(int vertexA, int vertexB) {
    adjacencyLists[vertexA].push_back(vertexB);
    adjacencyLists[vertexB].push_back(vertexA);
}

int Graph::getVertexCount() const {
    return vertexCount;
}

void Graph::showFriends() {
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;

        for (int j = 0; j < getVertexCount(); ++j) {
            if (std::find(adjacencyLists[i].begin(), adjacencyLists[i].end(), j) != adjacencyLists[i].end()) {
                ++counter;
            }
        }
    }
}

void Graph::showFriendsOptimized() {
    #pragma omp parallel for
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;

        #pragma omp parallel for
        for (int j = 0; j < getVertexCount(); ++j) {
            if (std::find(adjacencyLists[i].begin(), adjacencyLists[i].end(), j) != adjacencyLists[i].end()) {
                ++counter;
//                std::cout << i << " " << j << " " << counter << std::endl;
            }
        }
    }
}
#pragma clang diagnostic pop