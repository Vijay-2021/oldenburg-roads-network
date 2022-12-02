#pragma once
#include "../includes/Graph.hpp"
#include <unordered_map>

class BFS {
    public:
        /**
         * Default constructor.
        */
        BFS();

        /**
         * Performs BFS on a graph and records distances to get to each node from the starting
         * node during the traversal.
         * 
         * @param g The graph to traverse.
         * @return A map of distances to get to each node from the start node using BFS
        */
        std::unordered_map<int, double> performBFS(const Graph& g); 

        /**
         * Uses BFS to count the number of components in a graph.
         * 
         * @param g The graph to traverse.
         * @return Number of components discovered in the graph.
        */
        int countComponents(const Graph& g); 

    private:

        /**
         * Helper function that performs BFS on a graph
         * 
         * @param g The graph to traverse.
         * @param vertex Starting node in the traversal.
        */
        void BFS_helper(const Graph& g, int vertex);

        /**
         * Helper function to check BFS is traversing correctly by saving a map of
         * distances to get to each node from the starting node following the order
         * in BFS.
         * 
         * @param g The graph to traverse.
         * @param vertex Starting node in the traversal.
         * @param distances Map to store the distances in the traversal.
        */
        void BFS_helper(const Graph& g, int vertex, std::unordered_map<int, double>& distances); 

        std::vector<bool> visited_vertices_; //Vector of booleans to track visited vertices in BFS.
};