#pragma once
#include "includes/Graph.hpp"

class BFS {
    public:
        BFS();
        std::vector<int> performBFS(Graph g); //Output a labeling of edges on G as discovery and cross edges
        int countComponents(Graph g); //Count number of components using BFS

    private:
        void BFS_helper(Graph g, int vertex);
        Graph* graph_;
        std::vector<int> visited_vertices_;
        std::vector<int> visited_edges_;
};