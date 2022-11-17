#pragma once

#include "../includes/Graph.hpp"
#include "../includes/DisjointSets.h"
#include "../includes/PriorityQueue.h"
#include <vector>
#include <iostream>

using namespace std;

class Kruskals {
    public:
        Kruskals();
        void makeMST(Graph g);
        Graph getMST() const;
        double getWeight() const;
        // findShortestPath();

    private:
        DisjointSets forest_;
        PriorityQueue pq_;
        Graph min_span_tree_;
        double weight_;
};