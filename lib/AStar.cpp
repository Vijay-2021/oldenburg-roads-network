#include "Astar.hpp"
#include "../includes/PriorityQueue.hpp"
#include "../includes/DisjointSets.h"
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


std::vector<int> AStar::reconstruct_path(int start_location, int current_location) {
    /* Pseudocode
    total_path = {current} (current here is current_location)
    while current in cameFrom.keys:
        current = cameFrom[current]
        total_path.prepend(current)
    return total_path
     */
    
    std::vector<int> total_path;
    total_path.push_back(current_location);
    int current = current_location;
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
    openSet.insert(current); // Set of discovered nodes
    // cameFrom; // empty map
    for (int i = 0 ; i < g_.getNumVertices(); i++) {
        gScore[i] = 10000000000;
        fScore[i] = 10000000000;
    }
    gScore[start] = 0;
    fScore[start] = g_.getEuclideanDist(start, goal);
    while(openSet.size() > 0) {
        Node current = openSet.remove(); // node in openSet having lowest fScore[] value
        if(current.vertex == goal) {
            return reconstruct_path(start, current.vertex);
        }
        for(int neighbor : g_.adjacent(current.vertex)){ // Neighbors of current based on matrix
            double tentative_gScore = gScore[current.vertex] + g_.getEuclideanDist(current.vertex, neighbor); // weights are also Euclidean distance!
            if(tentative_gScore < gScore[neighbor]){
                // cameFrom[neighbor] = current; // find data type for cameFrom
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