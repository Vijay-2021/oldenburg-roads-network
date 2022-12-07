#include "Graph.hpp"
#include "AStar.hpp"
#include "BFS.hpp"
#include "Kruskals.hpp"
#include "dataManager.hpp"
#include <iostream>

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name
              << " [path to vertices.txt] [path to edges.txt]"
              << std::endl;
}


int main(int argc, char* argv[]) {
    std::string inVerticesFile = "";
    std::string inEdgeFile = "";

    if (argc < 3 && argc > 1) {
        show_usage(argv[0]);
        return 1;
    }

    if (argc == 1) {
        inVerticesFile = "../data/vertices.txt";
        inEdgeFile = "../data/edges.txt";

        std::cout << "main is running " << std::endl;

        Graph g;
        g = loadGraph(inVerticesFile, inEdgeFile);

        BFS bfs;
        Kruskals kruskals;
        kruskals.makeMST(g);
        std::cout << "Density: " << kruskals.getDensity() << std::endl;
        std::cout << "Number of Components: " << bfs.countComponents(g) << std::endl;
        
    }

    if (argc == 3) {
        inVerticesFile = argv[1];
        inEdgeFile = argv[2];

        std::cout << "main is running " << std::endl;

        Graph g;
        g = loadGraph(inVerticesFile, inEdgeFile);

        if (!g.getNumVertices()) {
            cerr << "ERROR: Cannot parse graph from input files " << inVerticesFile << " " << inEdgeFile
            << endl;
            exit(2);
        }

        BFS bfs;
        Kruskals kruskals;
        kruskals.makeMST(g);
        std::cout << "Density: " << kruskals.getDensity() << std::endl;
        std::cout << "Number of Components: " << bfs.countComponents(g) << std::endl;
    }
}