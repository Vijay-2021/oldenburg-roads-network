#include "Graph.hpp"
#include "AStar.hpp"
#include "BFS.hpp"
#include "Kruskals.hpp"
#include "dataManager.hpp"
#include <iostream>

int main(){
    std::cout << "main is running " << std::endl;

    Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    BFS bfs;

    std::cout << "Number of Components: " << bfs.countComponents(g) << std::endl;
    return 0;
}