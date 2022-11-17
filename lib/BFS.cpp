#include "BFS.hpp"
#include <queue>
#include <iostream>

BFS::BFS(){}

std::vector<int> BFS::performBFS(Graph* g) {
    graph_ = g;
    int numVertices = g->getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);
    visited_edges_ = std::vector<std::vector<int>>(numVertices, std::vector<int>(numVertices, -1));

    for (int v = 0; v < numVertices; v++) {
        if (visited_vertices_[v] == false) {
            BFS_helper(v);
        }
    }

    std::vector<int> edges;

    int count = 0;
    for (auto row: visited_edges_) {
        for (auto elem: row) {
            if (elem != -1) {
                // std::cout << elem << std::endl;
                edges.push_back(elem);
                if (elem == 0) {
                    count++;
                }
            }
        }
    }
    std::cout << "Count: " << count;
    std::cout << edges.size();
    return edges;
}

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
            int larger = -1;
            int smaller = -1;
            if (v < neighbor) {
                larger = neighbor;
                smaller = v;
            } else {
                larger = v;
                smaller = neighbor;
            }

            if (visited_vertices_[neighbor] == false) {
                visited_edges_[smaller][larger] = 1;
                visited_vertices_[neighbor] = true;
                q.push(neighbor);
            } else if (visited_edges_[smaller][larger] == -1) {
                visited_edges_[smaller][larger] = 0;
            }
        }
    }
    
}
