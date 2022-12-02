#pragma once
#include "../includes/Graph.hpp"
#include <unordered_map>

class BFS {
    public:
        BFS();
        std::unordered_map<int, double> performBFS(Graph* g); //Outputs a map of the path length to get to each node from the start node using BFS
        int countComponents(Graph* g); //Count number of components using BFS
       

    private:
        void BFS_helper(int vertex);
        void BFS_helper(int vertex, std::unordered_map<int, double>& distances);
        Graph* graph_;
        std::vector<bool> visited_vertices_;
        std::vector<std::vector<int>> visited_edges_;
};