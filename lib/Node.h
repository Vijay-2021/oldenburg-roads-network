#pragma once

/**
 * Node struct for A*
 * This is used for the priority queue in A*. We want to run A* on the vertices of the graph, however we want priority to be 
 * assigned by the FScore, so we use a struct for this
 */

struct Node {
    int vertex;
    double fscore;
    Node(int vert, double f) {
        vertex = vert;
        fscore = f;
    }
    bool operator==(const Node& n2) const {
        return vertex == n2.vertex && fscore == n2.fscore;
    }
    bool operator<(const Node& n2) const {
        return fscore < n2.fscore;
    }
};

