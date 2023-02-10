#include "Graph.hpp"
#include "AStar.hpp"
#include "BFS.hpp"
#include "Kruskals.hpp"
#include "dataManager.hpp"
#include <iostream>
#include <string> 


static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name
              << " [path to vertices.txt] [path to edges.txt]"
              << " [start vertex] [stop vertex]"
              << std::endl;
}

/**
Parse arguments. 
*/
int main(int argc, char* argv[]) {
    std::string inVerticesFile = "";
    std::string inEdgeFile = "";


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
    else if (argc == 3) {
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
    } else if (argc == 5) {
        inVerticesFile = argv[1];
        inEdgeFile = argv[2];
        int start = std::stoi(argv[3]);
        int stop = std::stoi(argv[4]);

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
        AStar a_star_runner(g);
        std::vector<int> path = a_star_runner.AStar_func(start, stop);
        kruskals.makeMST(g);

        std::cout << "Number of roads on shortest path: " << path.size() << std::endl; 
        std::cout << "Density: " << kruskals.getDensity() << std::endl;
        std::cout << "Number of Components: " << bfs.countComponents(g) << std::endl;
    } else {
        show_usage(argv[0]);
        return 1;
    }
}
