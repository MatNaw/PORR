#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <algorithm>
#include "Graph.h"

void Graph::addEdge(int vertexA, int vertexB) {
    int first = std::max(vertexA, vertexB);
    int second = std::min(vertexA, vertexB);
    adjacencyMatrix[first - 1][second - 1] = 1;
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