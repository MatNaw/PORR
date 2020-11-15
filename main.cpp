#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <limits>
#include "Graph.h"

std::unique_ptr<Graph> extractFileToGraph(const std::string& fileName) {
    std::unique_ptr<Graph> graph;
    std::string line;
    std::ifstream fin(fileName);
    int vertexNumber = 0;
    int edgesNumber = 0;

    while (getline(fin, line)) {
        // omit comments section
        if (line[0] == '%')
            continue;
        else {
            std::stringstream ss;
            ss << line;

            if (vertexNumber == 0) {
                // space delimiter to omit first value
                ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                // read the number of vertices and the number of edges
                ss >> vertexNumber >> edgesNumber;
                graph = std::make_unique<Graph>(vertexNumber);
            }
            else {
                // read every particular edge
                int vertexA, vertexB;
                ss >> vertexA >> vertexB;

                graph->addEdge(vertexA, vertexB);
            }
        }
    }

    fin.close();
    return std::move(graph);
}

int main() {
    //std::unique_ptr<Graph> graph = extractFileToGraph("../input/karate.txt");
    //std::unique_ptr<Graph> graph = extractFileToGraph("../input/dolphins.txt");
    std::unique_ptr<Graph> graph = extractFileToGraph("../input/emails.txt");
    graph->showFriends();
}
