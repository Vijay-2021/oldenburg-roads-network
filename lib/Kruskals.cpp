#include "Kruskals.hpp"

void Kruskals::makeMST(Graph g) {
    int N = g.getNumVertices();
    forest_.addelements(N);

    int* cols = g.getAdjColsArray();
    double* distances = g.getAdjDataArray();
    int* rowptr = g.getAdjRowPtrArray();

    int row = 0;
    int counter = 0;
    for (int i = 0; i < g.getNumEdges(); i++) {
        Edge e = {row, cols[i], distances[i]};
        pq_.insert(e);
        counter++;
        if (counter == rowptr[row]) {
            row++;
            counter = 0;
        }
    }

    while (min_span_tree_.getNumEdges() < N - 1) {
        Edge e = pq_.remove();
        if (forest_.find(e.v1) != forest_.find(e.v2)) {
            // @TODO insert edge and vertices to min_span_tree (e.distance, e.v1, e.v2)
            forest_.setunion(forest_.find(e.v1), forest_.find(e.v2));
        }
    }
}