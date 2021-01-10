#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <memory>
#include <limits>
#include "Graph.h"

std::unique_ptr<Graph> extractFileToGraph(const std::string& fileName) {
    std::unique_ptr<Graph> graph;
    std::string line;
    std::ifstream fin(fileName);
    int vertexNumber = 0;
    int edgesNumber = 0;

    //#pragma omp parallel
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

void showExecutionTime(std::chrono::duration<double, std::milli> elapsed_time) {
    std::cout << "Execution time: " << elapsed_time.count() << std::endl << std::endl;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::unique_ptr<Graph> graph = extractFileToGraph("../input/list512k.txt");

//    //sequential solution
//    auto start = std::chrono::high_resolution_clock::now(); 1200
    graph->showFriends();
//    auto end = std::chrono::high_resolution_clock::now(); karate - 30 ms ; list32k - 14172 ms ; list128k - 57492 ms ; list256k - 119163 ms ; list512k - 119163 ms
//
//    std::cout << "Sequential solution:" << std::endl;
//    showExecutionTime(end - start);
//
//    //parallel solution (OpenMP)
//    start = std::chrono::high_resolution_clock::now();
//    graph->showFriendsOptimized();
//    end = std::chrono::high_resolution_clock::now();

//    std::cout << "Parallel solution (OpenMP):" << std::endl;
    showExecutionTime(std::chrono::high_resolution_clock::now() - start);
}
