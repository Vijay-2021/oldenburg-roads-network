#include <catch2/catch_test_macros.hpp>
#include "../includes/Graph.hpp"
#include "../lib/Kruskals.hpp"
#include "../includes/PriorityQueue.hpp"
#include "../includes/Edge.h"
#include "dataManager.hpp"
#include <iostream>

using namespace std;


TEST_CASE("Test Priority Queue Insertion", "[Kruskals]") {
    PriorityQueue<Edge> pq;
    Edge e1 = {0, 1, 5.0};
    pq.insert(e1);
    REQUIRE(pq.getElems().size() == 1);
    REQUIRE(e1 == pq.remove());

    Edge e2 = {0, 1, 5.0}; Edge e3 = {2, 3, 7.0}; Edge e4 = {0, 2, 2.0}; 
    Edge e5 = {4, 5, 9.0}; Edge e6 = {2, 4, 8.0}; Edge e7 = {0, 5, 1.0};

    pq.insert(e2); pq.insert(e3); pq.insert(e4); pq.insert(e5); pq.insert(e6); pq.insert(e7);

    REQUIRE(pq.getElems().size() == 6);

    vector<Edge> expected1 = {e7, e3, e4, e5, e6, e2};
    bool matches = pq.getElems() == expected1;
    REQUIRE(matches == true);
}
TEST_CASE("Test Priority Queue Removal", "[Kruskals]") {
    PriorityQueue<Edge> pq;

    Edge e2 = {0, 1, 5.0}; Edge e3 = {2, 3, 7.0}; Edge e4 = {0, 2, 2.0}; 
    Edge e5 = {4, 5, 9.0}; Edge e6 = {2, 4, 8.0}; Edge e7 = {0, 5, 1.0};

    pq.insert(e2); pq.insert(e3); pq.insert(e4); pq.insert(e5); pq.insert(e6); pq.insert(e7);

    vector<Edge> sorted = {e7, e4, e2, e3, e6, e5};
    for (unsigned i = 0; i < sorted.size(); i++) {
        REQUIRE(sorted.at(i) == pq.remove());
    }
}
TEST_CASE("DisjointSets addElements1", "[Kruskals]")
{
	DisjointSets disjSets;
	disjSets.addelements(5);
	REQUIRE(3 == disjSets.find(3));
}

TEST_CASE("DisjointSets addElements2", "[Kruskals]")
{
	DisjointSets disjSets;
	disjSets.addelements(5);
	REQUIRE(0 == disjSets.find(0));
	disjSets.addelements(5);
	REQUIRE(9 == disjSets.find(9));
}
TEST_CASE("DisjointSets testFindAndSetUnion1", "[Kruskals]")
{
	DisjointSets disjSets;
	disjSets.addelements(4);
	disjSets.setunion(1, 2);
	REQUIRE(disjSets.find(2) == disjSets.find(1));
}

TEST_CASE("DisjointSets testFindAndSetUnion2", "[Kruskals]")
{
	DisjointSets disjSets;
	disjSets.addelements(10);
	disjSets.setunion(4, 8);
	disjSets.setunion(1, 3);
	disjSets.setunion(1, 5);
	disjSets.setunion(8, 3);
	disjSets.setunion(6, 7);
	disjSets.setunion(2, 8);
	disjSets.setunion(7, 1);
	int root = disjSets.find(1);
	for (int i = 2; i <= 8; i++) {
		REQUIRE(root == disjSets.find(i));
	}
		
	REQUIRE(disjSets.find(0) != disjSets.find(9));
}

TEST_CASE("DisjointSets testFindAndSetUnion3", "[Kruskals]")
{
	DisjointSets disjSets;
	disjSets.addelements(8);

	disjSets.setunion(1, 2);
	disjSets.setunion(1, 3);
	disjSets.setunion(4, 5);
	disjSets.setunion(4, 6);
	disjSets.setunion(3, 6);

	REQUIRE(disjSets.find(4) == disjSets.find(1));
	REQUIRE(disjSets.find(0) != disjSets.find(4));
}
// @TODO Test cases for makeMST
TEST_CASE("Kruskals makeMST", "[Kruskals]") {
	Graph g;
    g = loadGraph("../data/vertices.txt", "../data/edges.txt");
	Kruskals k;
	k.makeMST(g);
	Graph t = k.getMST();
	printEdgesToFile("kruskalsedges.txt", t);
	printVerticesToFile("kruskalsvertices.txt", t);
	
	REQUIRE(t.getNumEdges() == g.getNumVertices() - 1);
}

TEST_CASE("Kruskal Weight Test Simple", "[Kruskals]") {
	Graph g;
	g = loadGraph("../data/vertices_simple.txt", "../data/edges_simple.txt");
	Kruskals k;
	k.makeMST(g);
	Graph t = k.getMST();
	printEdgesToFile("test_simple_edges.txt", t);
	REQUIRE(k.getWeight() == 16.0);
}

TEST_CASE("Kruskal Weight Medium 1", "[Kruskals]") {
	Graph g;
	g = loadGraph("../data/testvertices1.txt", "../data/testedges1.txt");
	Kruskals k;
	k.makeMST(g);
	Graph t = k.getMST();
	printEdgesToFile("test_one_edges.txt", t);
	REQUIRE(k.getWeight() == 21.0);
}

TEST_CASE("Kruskal Weight Test Medium 2", "[Kruskals]") {
	Graph g;
	g = loadGraph("../data/vertices_medium.txt", "../data/edges_medium.txt");
	Kruskals k;
	k.makeMST(g);
	Graph t = k.getMST();
	printEdgesToFile("test_two_edges.txt", t);
	REQUIRE(t.getNumEdges() == 10);
	REQUIRE(k.getWeight() == 41.0);
}
