#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
#ifndef PORR_GRAPH_H
#define PORR_GRAPH_H

#include <string>
#include <map>
#include <vector>

class Graph {
public:
    explicit Graph(int vertexCount): vertexCount(vertexCount)
    {
    }

    void addEdge(int vertexA, int vertexB);

    int getVertexCount() const;

    //sequential
    void showFriends();

    //parallel with OpenMP
    void showFriendsOptimized();

private:
    const int vertexCount;
    std::map<int, std::vector<int>> adjacencyLists;
};


#endif //PORR_GRAPH_H

#pragma clang diagnostic pop