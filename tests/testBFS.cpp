#include <catch2/catch_test_macros.hpp>
#include "../includes/Graph.hpp"
#include "../includes/dataManager.hpp"
#include "../lib/BFS.hpp"

TEST_CASE("Correct Number of Components 1", "[BFS]") {
    Graph g;
    BFS bfs;
    g = loadGraph("../data/threeConnectedCompVertices.txt", "../data/threeConnectedCompEdges.txt");
    REQUIRE(bfs.countComponents(&g) == 3);
}

TEST_CASE("Correct Number of Components 2", "[BFS]") {
    Graph g;
    BFS bfs;
    g = loadGraph("../data/oneConnectedCompVertices.txt", "../data/oneConnectedCompEdges.txt");
    REQUIRE(bfs.countComponents(&g) == 1);
}

TEST_CASE("Correct Number of Components Our Dataset", "[BFS]") {
    Graph g;
    BFS bfs;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    REQUIRE(bfs.countComponents(&g) == 1);
}

TEST_CASE("Correct Path Lengths in Traversal", "[BFS]") {
    Graph g;
    g = loadGraph("../data/randomgraphVertices.txt", "../data/randomgraphEdges.txt");

    BFS bfs;
    std::unordered_map<int, double> BFSPath = bfs.performBFS(&g);

    //Map of the expected values
    std::unordered_map<int, double> soln;
    soln[0] = 0.0;
    soln[1] = 3.8;
    soln[2] = 2.1;
    soln[3] = 3.2;
    soln[4] = 6.7;
    soln[5] = 16.8;
    soln[6] = 12.0;
    soln[7] = 4.2;

    //Compare the soln map to the bfs map
    const double epsilon = 1e-5; //Used to compare doubles (floating point shenanigans)
    for (const auto& elem: soln) { 
        int k = elem.first;
        REQUIRE(BFSPath.find(k) != BFSPath.end());
        REQUIRE(std::abs(BFSPath[k]-soln[k]) <= epsilon * std::abs(soln[k]));
    }

}

