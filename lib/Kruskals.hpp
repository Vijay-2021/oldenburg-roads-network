#pragma once

#include "../includes/Graph.hpp"
#include "../includes/DisjointSets.hpp"
#include "../includes/PriorityQueue.hpp"
#include "../includes/Edge.h"
#include <vector>
#include <iostream>

using namespace std;

class Kruskals {
    public:
        Kruskals();
        void makeMST(Graph g);
        Graph getMST() const;
        double getWeight() const;
        double getDensity() const;
        // findShortestPath();

    private:
        DisjointSets forest_;
        PriorityQueue<Edge> pq_;
        Graph min_span_tree_;
        double weight_;
};