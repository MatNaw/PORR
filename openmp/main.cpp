#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <memory>
#include <limits>
#include "Graph.h"

#ifndef THREADS_NUMBER
#define THREADS_NUMBER 8
#endif

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

auto calcExecutionTime(std::chrono::time_point<std::chrono::steady_clock> start,
                       std::chrono::time_point<std::chrono::steady_clock> end) {
    std::chrono::duration<double, std::milli> elapsedTime = end - start;
    return elapsedTime.count();
}

int main() {
    // For 'karate' and 'dolphins' datasets -> OpenMP solution time is higher than the sequential solution time
    // (probably these are too small datasets)
    std::unique_ptr<Graph> graph = extractFileToGraph("../input/list32k.txt");
    for (int threadsNumber = 1; threadsNumber <= THREADS_NUMBER; threadsNumber++) {
        std::cout << "Threads: " << threadsNumber << std::endl;

        //sequential solution
        auto start = std::chrono::high_resolution_clock::now();
        graph->showFriends();
        auto sequential = calcExecutionTime(start, std::chrono::high_resolution_clock::now());


        //parallel solution (OpenMP)
        start = std::chrono::high_resolution_clock::now();
        graph->showFriendsOptimized(threadsNumber);
        auto parallel = calcExecutionTime(start, std::chrono::high_resolution_clock::now());

        std::cout << "Sequential / parallel (OpenMP): " << std::endl << sequential << " " << parallel << std::endl;
    }
}
