#include "BFS.hpp"
#include <queue>

BFS::BFS(){}

std::vector<int> BFS::performBFS(Graph* g) {
    return std::vector<int>();
}

int BFS::countComponents(Graph* g) {
    graph_ = g;
    int numVertices = g->getNumVertices();
    visited_vertices_ = std::vector<bool>(numVertices, false);

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
