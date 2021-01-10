#ifndef PORR_GRAPH_H
#define PORR_GRAPH_H

#include <string>
#include <map>

class Graph {
public:
    explicit Graph(int vertexCount): vertexCount(vertexCount)
    {
        //adjacencyMatrix = new int*[vertexCount];
        for (int i = 0; i < vertexCount; ++i)
        {
            //adjacencyMatrix[i] = new int[i + 1];
            adjacencyMatrix_test[i] = 0;
//            for (int j = 0; j < i + 1; ++j) {
//                //adjacencyMatrix[i][j] = 0;
//            }
        }
    }

    void addEdge(int vertexA, int vertexB);

    int getVertexCount() const;

    //sequential
    void showFriends();

    //parallel with OpenMP
    void showFriendsOptimized();

private:
    const int vertexCount;
    int **adjacencyMatrix;
    std::map<int, int> adjacencyMatrix_test;
};


#endif //PORR_GRAPH_H