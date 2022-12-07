#include "Astar.hpp"
#include "../includes/PriorityQueue.hpp"
#include "../includes/DisjointSets.hpp"
#include "../includes/Edge.h"

#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream> 


using namespace std;

AStar::AStar(Graph g){
    g_ = g;
    cameFrom = {};
    gScore = {};
    fScore = {};
}


std::vector<int> AStar::reconstruct_path(int current_location) {
    std::vector<int> total_path;
    total_path.push_back(current_location);
    int current = current_location;

    // Stop once the key is not in the came from map
    while (cameFrom.contains(current)) {
        current = cameFrom[current];
        total_path.push_back(current);
    }
    std::reverse(total_path.begin(), total_path.end());
    reset();
    return total_path;
}

void AStar::reset() {
    openSet.clear();
    cameFrom.clear();
    gScore.clear();
    fScore.clear();
}
std::vector<int> AStar::AStar_func(int start, int goal){
    Node current(start, g_.getEuclideanDist(start, goal));
    openSet.insert(current);
    for (int i = 0 ; i < g_.getNumVertices(); i++) {
        gScore[i] = 10000000000; // sets the original distance to "infinity"; cheapest path from start to n that is known at time
        fScore[i] = 10000000000; // sets the original distance to "infinity"; fScore[i] = gScore[i] + getEuclideanDist()
    }
    gScore[start] = 0;
    fScore[start] = g_.getEuclideanDist(start, goal);
    while(openSet.size() > 0) {
        Node current = openSet.remove(); // node in openSet having lowest fScore[] value
        if(current.vertex == goal) {
            return reconstruct_path(current.vertex);
        }
        for(int neighbor : g_.adjacent(current.vertex)){ // Neighbors of current based on matrix
            double tentative_gScore = gScore[current.vertex] + g_.getEuclideanDist(current.vertex, neighbor); // weights are also Euclidean distance!
            if(tentative_gScore < gScore[neighbor]){
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = tentative_gScore + g_.getEuclideanDist(neighbor, goal);
                cameFrom[neighbor] = current.vertex;
                bool in_set = false;
                for (unsigned i = 0; i < openSet.size(); i++) {
                    if (neighbor == openSet.getElems()[i].vertex) {
                        in_set = true;
                        Node new_node = Node(neighbor, fScore[neighbor]);
                        openSet.updateElem(i, new_node);
                    }
                }
                if(!in_set) {
                    openSet.insert(Node(neighbor, fScore[neighbor])); 
                }
            }
        }
    }
    reset();
    std::vector<int> output; 
    return output; // Open set is empty, goal was never reached, returns failure
}