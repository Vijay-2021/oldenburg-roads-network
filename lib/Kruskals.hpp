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

        /***
        * @param g The input Graph
        * Generates the minimum spanning tree for the graph g
        * This is done through Kruskals algorithim. We start at a node 
        */
        void makeMST(Graph g);

        /**
        * Returns the stored minimum spanning tree
        */
        Graph getMST() const;

        /**
        * Returns the total weight of all of the edges in the minimum spanning tree
        */
        double getWeight() const;

        /***
        * Returns the "density"(total weight / num_edges) / the maximum possible distance 
        * What this means is that the box that contains the graph is 10,000 * 10,000. Which in this case means that the maximum 
        * possible  distance is sqrt(2)*10000. Now to measure the "density" of the road network we compare the average length of 
        * a path between two   nodes to the max length, and this will tell us how close nodes are in relative terms. There are no 
        * units since these are in normalized coordinates. 
        */
        double getDensity() const;

    private:
        DisjointSets forest_;
        PriorityQueue<Edge> pq_;
        Graph min_span_tree_;
        double weight_;
        static constexpr double kMaxXDistance = 10000;
        static constexpr double kMaxYDistance = 10000;
};