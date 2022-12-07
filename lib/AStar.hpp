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
        /**
        * @param g The graph that the AStar algorithim will be run on
        */
        AStar(Graph g);

        /***
        * Resets our map 
        */
        void reset();

        /***
        * @param current_location node to trace the path back from
        * Reconstructs the path taken to get to a given location by the AStar algorithim
        * This is done using the came from map
        */
        std::vector<int> reconstruct_path(int current_location); 

        /***
        * @param start the node that the path should start from
        * @param goal the node that the path should end on
        * Finds the shortest path between the start and the goal using the AStar algorithim with the Euclidean distance heuristic
        */
        std::vector<int> AStar_func(int start, int goal);
        
    private:
        PriorityQueue<Node> openSet;
        std::unordered_map<int, int> cameFrom;
        std::unordered_map<int, double> gScore;
        std::unordered_map<int , double> fScore;
        Graph g_;
};