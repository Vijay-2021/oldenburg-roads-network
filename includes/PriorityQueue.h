#pragma once

#include "Edge.h"

#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
class PriorityQueue {
    public:
        bool higherPriority(Edge e1, Edge e2);
        void swap(Edge& e1, Edge& e2);
        void insert(Edge e);
        Edge remove();
        bool hasAChild(size_t currentIdx) const;
        unsigned maxPriorityChild(unsigned idx);
        void heapifyDown(unsigned idx);
        void heapifyUp(unsigned idx);
        vector<Edge> getElems() const;
    private:
        vector<Edge> elems_;
};