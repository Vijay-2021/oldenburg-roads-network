#pragma once

struct Edge {
    int v1;
    int v2;
    double distance;
    bool operator==(const Edge& e2) const {
        return v1 == e2.v1 && v2 == e2.v2 && distance == e2.distance;
    }
};

