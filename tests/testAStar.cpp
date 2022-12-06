#include <catch2/catch_test_macros.hpp>
#include "AStar.hpp"
#include "Graph.hpp"
#include "../includes/dataManager.hpp"
#include <iostream>

#include <cmath> 

TEST_CASE("Test Euclidean Distance", "[AStar]") {
    Graph g; 
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    REQUIRE(std::abs(g.getEuclideanDist(0, 6104)  - 3567.9470371456) <= 0.01); //check edges on the edge
    REQUIRE(std::abs(g.getEuclideanDist(0, 1) - g.edgeValue(1)) <= 0.01); // check adjacent edges
}

TEST_CASE("Test AStar on Our Dataset", "[AStar]") {
    Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    AStar astar_runner(g);

    std::vector<int> path_one = astar_runner.AStar_func(0, 6104);
    std::vector<int> path_two = astar_runner.AStar_func(47, 3045);

    REQUIRE(path_one[0] == 0);
    REQUIRE(path_one[path_one.size() - 1] == 6104);
    for (unsigned i = 0; i < path_one.size() - 1; i++) {
        REQUIRE(g.areAdjacent(path_one[i], path_one[i + 1]));
    }

    REQUIRE(path_two[0] == 47);
    REQUIRE(path_two[path_two.size() - 1] == 3045);
    for (unsigned i = 0; i < path_two.size() - 1; i++) {
        REQUIRE(g.areAdjacent(path_two[i], path_two[i+1]));
    }
}

TEST_CASE("Test AStar Traversal", "[AStar]") {
    Graph g;
    g = loadGraph("../data/testAStarVertices.txt", "../data/testAStarEdges.txt");
    AStar astar_runner(g);
    std::vector<int> path = astar_runner.AStar_func(0, 7);
    REQUIRE(path.size() == 5);
    REQUIRE(path[0] == 0);
    REQUIRE(path[1] == 2);
    REQUIRE(path[2] == 3);
    REQUIRE(path[3] == 5);
    REQUIRE(path[4] == 7);
}
