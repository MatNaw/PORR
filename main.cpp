#include <iostream>
#include "Graph.h"

int main(int argc, char **argv) {

    int vertexCount = 10;

    Graph graph(vertexCount);
    graph.addEdge(1, 2);
    graph.addEdge(5, 8);

    std::cout << graph[1][1] << std::endl;
    std::cout << graph[1][2] << std::endl;
    std::cout << graph[5][8] << std::endl;
    std::cout << graph[8][5] << std::endl;
    std::cout << graph[1][8] << std::endl;
}
