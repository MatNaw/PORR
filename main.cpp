#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "Graph.h"

std::unique_ptr<Graph> extractFileToGraph(std::string fileName) {
    int vertexNumber = 0;
    int edgesNumber = 0;
    std::unique_ptr<Graph> g;
    std::string line;
    std::ifstream fin(fileName);
    while (getline(fin, line)) {
        if (line[0] == '%')
            continue;
        else if (vertexNumber == 0) {
            //wczytanie liczby wierzcholkow i krawedzi
            std::stringstream ss;
            ss << line;
            ss >> vertexNumber >> vertexNumber >> edgesNumber;
            g = std::make_unique<Graph>(vertexNumber);
        } else {
            //wczytywanie krawedzi
            int a, b;
            std::stringstream ss;
            ss << line;
            ss >> a >> b;
            g->addEdge(a, b);
        }
    }
    fin.close();
    return std::move(g);
}

int main(int argc, char **argv) {

    std::unique_ptr<Graph> g = extractFileToGraph("C:/Users/rados/CLionProjects/PORR/input/karate.txt");
    std::cout << g->getEdge(1, 5) << std::endl;
}
