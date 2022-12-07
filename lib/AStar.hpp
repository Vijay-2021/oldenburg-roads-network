#pragma once

#include "../includes/PriorityQueue.hpp"
#include "../includes/DisjointSets.hpp"
#include "../includes/Edge.h"
#include <map>
#include <unordered_map>
#include <list>
#include "../includes/Graph.hpp"
#include "Node.h"

using namespace std;

class AStar {
    public:
        // Constructor
        AStar(Graph g);

        void reset();
        std::vector<int> reconstruct_path(int start_location, int current_location); 
        std::vector<int> AStar_func(int start, int goal);
        
    private:
        PriorityQueue<Node> openSet;
        std::unordered_map<int, int> cameFrom; // Queue, Stack?; Map
        std::unordered_map<int, double> gScore;
        std::unordered_map<int , double> fScore;
        Graph g_;
};