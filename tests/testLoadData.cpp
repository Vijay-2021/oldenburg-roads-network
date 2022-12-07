#include <catch2/catch_test_macros.hpp>
#include "Graph.hpp"
#include "dataManager.hpp"
#include <algorithm>

TEST_CASE("Test Loads Vertices and Edges", "[weight=1][part=1]") {
    Graph g; 
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    REQUIRE(g.getNumVertices() == 6105);
    REQUIRE(g.getNumEdges() == 7035*2);
}

TEST_CASE("Test Are Adjacent", "[weight=1][part=1]") {
    // random tests: 
    Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    REQUIRE_FALSE(g.areAdjacent(5994, 3));
    REQUIRE_FALSE(g.areAdjacent(5995, 5996)); // pick two nodes we know aren't adjacent
    REQUIRE_FALSE(g.areAdjacent(3000, 4000));
    REQUIRE_FALSE(g.areAdjacent(1002, 7));
    REQUIRE(g.areAdjacent(2627, 2629));
    
    //edge cases: 
    REQUIRE(g.areAdjacent(5994,5996)); // test last line in file
    REQUIRE(g.areAdjacent(1609, 1622));
    REQUIRE(g.areAdjacent(2262, 6104)); // test last vertex
    REQUIRE(g.areAdjacent(0, 1)); // test first vertex
    REQUIRE_FALSE(g.areAdjacent(0,3));

    //test reverse: 
    REQUIRE(g.areAdjacent(5996,5994));
    REQUIRE(g.areAdjacent(2162, 2159));
}

TEST_CASE("Test Weights are correct", "[weight=1][part=1]") {
    //this is predicated on the fact that are adjacent works  
    Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    REQUIRE(g.edgeValue(g.indexOfAdjacentEdge(2627, 2629)) == 34.945984);
    
    //edge cases: 
    REQUIRE(g.edgeValue(g.indexOfAdjacentEdge(5994, 5996)) == 107.235260); // test last file
    REQUIRE(g.edgeValue(g.indexOfAdjacentEdge(1609, 1622)) == 57.403187); // test first file
    REQUIRE(g.edgeValue(g.indexOfAdjacentEdge(2262, 6104)) == 77.312416); // test last
    REQUIRE(g.edgeValue(g.indexOfAdjacentEdge(0, 1)) == 95.952362); //test first

    //test reverse: 
    REQUIRE(g.areAdjacent(5996,5994));
    REQUIRE(g.areAdjacent(2162, 2159));    

}

TEST_CASE("Test adjacent works", "[weight=1][part=1]") {
    //Test that adjacent returns a valid list of adjacent vertices to the provided vertex  
    Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
    std::vector<int> adjacentList = g.adjacent(2444);

    //Correct adjacent vertices
    REQUIRE(adjacentList.size() == 3);
    REQUIRE(std::find(adjacentList.begin(), adjacentList.end(), 2460) != adjacentList.end());
    REQUIRE(std::find(adjacentList.begin(), adjacentList.end(), 2476) != adjacentList.end());
    REQUIRE(std::find(adjacentList.begin(), adjacentList.end(), 2433) != adjacentList.end());
    
    //One adjacent vertices
    adjacentList = g.adjacent(5435);
    REQUIRE(adjacentList.size() == 1);
    REQUIRE(std::find(adjacentList.begin(), adjacentList.end(), 5429) != adjacentList.end());
}