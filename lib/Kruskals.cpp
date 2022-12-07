#include "Kruskals.hpp"
#include <iostream>
#include <algorithm>

Kruskals::Kruskals() {
    // do nothing!
}

/***
* Returns the weight of the current minimum spanning tree
*/
double Kruskals::getWeight() const{
    return weight_;
}

void Kruskals::makeMST(Graph g) {
    unsigned N = g.getNumVertices();
    forest_.addelements(N);
    std::vector<int> vertices;
    std::vector<double> x_locs;
    std::vector<double> y_locs;
    int* cols = g.getAdjColsArray();
    double* distances = g.getAdjDataArray();
    int* rowptr = g.getAdjRowPtrArray();
    int row = 0;
    int counter = 0;
    weight_ = 0; // reset or initialize weight
    for (int i = 0; i < g.getNumEdges(); i++) {
        Edge e = {row, cols[i], distances[i]};
        pq_.insert(e);
        counter++; // row ptr 0 = 2, we want to go to row 1 once we have seen 2 values
        while (counter >= rowptr[row]) {
            row++;
        }
    } 
    std::vector<Edge> edges;
    std::vector<bool> seen; 
    for (int i = 0 ; i < g.getNumVertices(); i++) {
        seen.push_back(false);
    }
    while (edges.size() < N - 1 && pq_.getElems().size() > 0) {
        Edge e = pq_.remove();
        if (forest_.find(e.v1) != forest_.find(e.v2)) {
            weight_ += e.distance;
            // @TODO insert edge and vertices to min_span_tree (e.distance, e.v1, e.v2)
            forest_.setunion(forest_.find(e.v1), forest_.find(e.v2));
            edges.push_back(e);
            if (seen[e.v1] == false) {
                vertices.push_back(e.v1);
                seen[e.v1] = true;
            }
            if (seen[e.v2] == false) {
                vertices.push_back(e.v2);
                seen[e.v2] = true;
            }
        }
        
    }
    std::sort(vertices.begin(), vertices.end());
    for (unsigned i = 0; i < vertices.size(); i++) {
        x_locs.push_back(g.getX(vertices[i]));
        y_locs.push_back(g.getY(vertices[i]));
    }
    min_span_tree_ = Graph(vertices, x_locs, y_locs, edges);
}

Graph Kruskals::getMST() const {
    return min_span_tree_;
}

double Kruskals::getDensity() const {
    return (weight_ / (double)min_span_tree_.getNumEdges()); 
}