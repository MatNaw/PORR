#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <memory>
#include <limits>
#include <omp.h>
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

void showExecutionTime(std::chrono::duration<double, std::milli> elapsed_time) {
    std::cout << elapsed_time.count() << " ";
//    std::cout << "Execution time: " << elapsed_time.count() << std::endl << std::endl;
}

int main() {
    // For karate and dolphins datasets -> OpenMP solution time is higher than the sequential solution time
    // (probably too small datasets)
    //std::unique_ptr<Graph> graph = extractFileToGraph("../input/karate.txt");
    //std::unique_ptr<Graph> graph = extractFileToGraph("../input/dolphins.txt");
    std::unique_ptr<Graph> graph = extractFileToGraph("../input/list32k.txt");

    for (int i = 1; i <= 50; ++i) {
        omp_set_num_threads(i);
        std::cout << i << " ";

        //sequential solution
        auto start = std::chrono::high_resolution_clock::now();
        graph->showFriends();
        auto end = std::chrono::high_resolution_clock::now();
//        std::cout << "Sequential solution:" << std::endl;
        showExecutionTime(end - start);

        //parallel solution (OpenMP)
        start = std::chrono::high_resolution_clock::now();
        graph->showFriendsOptimized();
        end = std::chrono::high_resolution_clock::now();

//        std::cout << "Parallel solution (OpenMP):" << std::endl;
        showExecutionTime(end - start);
        std::cout << std::endl;
    }
}
