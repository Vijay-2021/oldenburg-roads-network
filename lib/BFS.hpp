#pragma once
#include "../includes/Graph.hpp"
#include <unordered_map>

class BFS {
    public:
        BFS();
        std::unordered_map<int, double> performBFS(const Graph& g); //Outputs a map of the distances to get to each node from the start node using BFS
        int countComponents(const Graph& g); //Count number of components using BFS

    private:
        void BFS_helper(const Graph&, int vertex); //Helper to run BFS on graph
        void BFS_helper(const Graph&, int vertex, std::unordered_map<int, double>& distances); //Helper to check that BFS is traversing correctly
        std::vector<bool> visited_vertices_;
};