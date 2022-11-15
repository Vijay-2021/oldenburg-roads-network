#pragma once

#include "../includes/Graph.hpp"
#include "../includes/DisjointSets.h"
#include "../includes/PriorityQueue.h"
#include <vector>

class Kruskals {
    public:
        Kruskals();
        void makeKruskalsTree(Graph g);
        // findShortestPath();

    private:
        DisjointSets ds;
        PriorityQueue pq;
        Graph min_span_tree_;
};