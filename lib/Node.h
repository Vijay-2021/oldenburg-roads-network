#pragma once

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

