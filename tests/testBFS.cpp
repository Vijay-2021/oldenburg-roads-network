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
