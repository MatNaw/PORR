#ifndef HELLOWORLD_GRAPH_H
#define HELLOWORLD_GRAPH_H

#include <string>

class Graph {
public:
    explicit Graph(int vertexCount): vertexCount(vertexCount)
    {
        adjacencyMatrix = new int*[vertexCount];
        for (int i = 0; i < vertexCount; ++i)
        {
            adjacencyMatrix[i] = new int[vertexCount];

            for (int j = 0; j < vertexCount; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int a, int b) {
        adjacencyMatrix[a-1][b-1] = 1;
        adjacencyMatrix[b-1][a-1] = 1;
    }

    int getEdge(int a, int b) {
        return adjacencyMatrix[a-1][b-1];
    }

//    int* operator[](int index)
//    {
//        return adjacencyMatrix[index];
//    }

    int getVertexCount() const {
        return vertexCount;
    }

private:
    int vertexCount;
    int **adjacencyMatrix;
};


#endif //HELLOWORLD_GRAPH_H
