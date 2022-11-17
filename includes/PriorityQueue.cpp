#include "PriorityQueue.h"

void PriorityQueue::insert(Edge e) {
    elems_.push_back(e);
    heapifyUp(elems_.size() - 1);
}
Edge PriorityQueue::remove() {
    Edge e = elems_.at(0);
    swap(elems_.at(0), elems_.at(elems_.size() - 1));
    elems_.pop_back();
    heapifyDown(0);
    return e;
}
void PriorityQueue::swap(Edge& e1, Edge& e2) {
    Edge temp = e1;
    e1 = e2;
    e2 = temp;
}
bool PriorityQueue::higherPriority(Edge e1, Edge e2) {
    return e1.distance < e2.distance;
}
unsigned PriorityQueue::maxPriorityChild(unsigned idx) {
    unsigned left_child_idx = 2 * idx + 1;
    unsigned right_child_idx = 2 * idx + 2;
    if (left_child_idx >= elems_.size()) {
        return right_child_idx;
    } else if (right_child_idx >= elems_.size()) {
        return left_child_idx;
    }
    Edge left_child = elems_.at(2 * idx + 1);
    Edge right_child = elems_.at(2 * idx + 2);
    if (higherPriority(left_child, right_child)) {
        return left_child_idx;
    } else {
        return right_child_idx;
    }
}
bool PriorityQueue::hasAChild(size_t idx) const {
    if (2 * idx + 1 >= elems_.size() && 2 * idx + 2 >= elems_.size()) {
        return false;
    }
    return true;
}
void PriorityQueue::heapifyDown(unsigned idx) {
    if (!hasAChild(idx)) {
        return;
    }
    size_t minChild = maxPriorityChild(idx);
    if (!higherPriority(elems_.at(idx), elems_.at(minChild))) {
        swap(elems_.at(idx), elems_.at(minChild));
        heapifyDown(minChild);
    }
}
void PriorityQueue::heapifyUp(unsigned idx) {
    if (idx == 0)
        return;
    unsigned parentIdx = floor((idx-1)/2);
    if (higherPriority(elems_[idx], elems_[parentIdx])) {
        swap(elems_[idx], elems_[parentIdx]);
        heapifyUp(parentIdx);
    }
}
vector<Edge> PriorityQueue::getElems() const {
    return elems_;
}