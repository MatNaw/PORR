#include <iostream>
#include "Graph.h"

void Graph::addEdge(int vertexA, int vertexB) {
    adjacencyMatrix[vertexA - 1][vertexB - 1] = 1;
    adjacencyMatrix[vertexB - 1][vertexA - 1] = 1;
}

int Graph::getEdge(int vertexA, int vertexB) {
    return adjacencyMatrix[vertexA - 1][vertexB - 1];
}

int Graph::getVertexCount() const {
    return vertexCount;
}

void Graph::showFriends() {
    for (int i = 0; i < getVertexCount(); ++i) {
        int counter = 0;
        std::cout << "Friends of " << i+1 << ": ";

        for (int j = 0; j < getVertexCount(); ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                ++counter;
                std::cout << j+1;

                if (j != getVertexCount() - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl << "Total number of friends: " << counter << std::endl << std::endl;
    }
    std::cout << "Searching finished!" << std::endl;
}