#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

Graph *extractFileToGraph(std::string fileName){
    int vertexNumber = 0;
    int edgesNumber = 0;
    Graph *g;
    std::string line;
//    std::ifstream fin(fileName, std::ifstream::in);
    std::ifstream fin;
    fin.open(fileName);
    if(fin.is_open()) {
        while (getline(fin, line)) {
            if (line[0] == '%')
                continue;
            else if (vertexNumber == 0) {
                //wczytanie liczby wierzcholkow i krawedzi
                fin >> vertexNumber >> vertexNumber >> edgesNumber;
                g = new Graph(vertexNumber);
            } else {
                //wczytywanie krawedzi
                int a, b;
                fin >> a >> b;
                g->addEdge(a, b);
            }
        }
    }
    fin.close();
    return g;
}

int main(int argc, char **argv) {

    Graph g = *(extractFileToGraph("D:/Studia/PORR/Projekt/Git/input/karate.txt"));
    std::cout << g[0][0] << std::endl;

}
