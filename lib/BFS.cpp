#include "BFS.hpp"
#include <queue>
#include <iostream>

BFS::BFS(){}

int BFS::countComponents(const Graph& g) {
    int numVertices = g.getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);

    int numComponents = 0;
    for (int v = 0; v < numVertices; v++) {
        if (visited_vertices_[v] == false) {
            BFS_helper(g, v);
            numComponents += 1;
        }
    }

    return numComponents;
}

std::unordered_map<int, double> BFS::performBFS(const Graph& g) {
    int numVertices = g.getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);

    std::unordered_map<int, double> distances;
    for (int v = 0; v < numVertices; v++) {
        if (visited_vertices_[v] == false) {
            distances[v] = 0;
            BFS_helper(g, v, distances);
        }
    }

    return distances;
}

void BFS::BFS_helper(const Graph& g, int vertex) {
    std::queue<int> q;
    visited_vertices_[vertex] = true;

    q.push(vertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: g.adjacent(v)) {
            if (visited_vertices_[neighbor] == false) {
                visited_vertices_[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
}

void BFS::BFS_helper(const Graph& g, int vertex, std::unordered_map<int, double>& distances) {
    std::queue<int> q;
    visited_vertices_[vertex] = true;

    q.push(vertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: g.adjacent(v)) {
            if (visited_vertices_[neighbor] == false) {
                visited_vertices_[neighbor] = true;
                q.push(neighbor);
                distances[neighbor] = distances[v] + g.edgeValue(g.indexOfAdjacentEdge(v, neighbor));
            }
        }
    }
}