#ifndef PORR_GRAPH_H
#define PORR_GRAPH_H

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

//    int* operator[](int index)
//    {
//        return adjacencyMatrix[index];
//    }

    void addEdge(int vertexA, int vertexB);

    int getEdge(int vertexA, int vertexB);

    int getVertexCount() const;

    void showFriends();

private:
    const int vertexCount;
    int **adjacencyMatrix;
};


#endif //PORR_GRAPH_H
