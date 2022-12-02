#include "BFS.hpp"
#include <queue>
#include <iostream>

BFS::BFS(){}

int BFS::countComponents(Graph* g) {
    graph_ = g;
    int numVertices = g->getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);
    visited_edges_ = std::vector<std::vector<int>>(numVertices, std::vector<int>(numVertices, -1));

    int numComponents = 0;
    for (int v = 0; v < numVertices; v++) {
        if (visited_vertices_[v] == false) {
            BFS_helper(v);
            numComponents += 1;
        }
    }

    return numComponents;
}

void BFS::BFS_helper(int vertex) {
    std::queue<int> q;
    visited_vertices_[vertex] = true;

    q.push(vertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: graph_->adjacent(v)) {
            if (visited_vertices_[neighbor] == false) {
                visited_vertices_[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
}

std::unordered_map<int, double> BFS::performBFS(Graph* g) {
    graph_ = g;
    int numVertices = g->getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);
    std::unordered_map<int, double> distances;


    for (int v = 0; v < numVertices; v++) {
        if (visited_vertices_[v] == false) {
            distances[v] = 0;
            BFS_helper(v, distances);
        }
    }

    return distances;
}

void BFS::BFS_helper(int vertex, std::unordered_map<int, double>& distances) {
    std::queue<int> q;
    visited_vertices_[vertex] = true;

    q.push(vertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: graph_->adjacent(v)) {
            if (visited_vertices_[neighbor] == false) {
                visited_vertices_[neighbor] = true;
                q.push(neighbor);
                distances[neighbor] = distances[v] + graph_->edgeValue(graph_->indexOfAdjacentEdge(v, neighbor));
            }
        }
    }
}