#pragma once

#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class PriorityQueue {
    public:
        bool higherPriority(T e1, T e2);
        void swap(T& e1, T& e2);
        void insert(T e);
        T remove();
        bool hasAChild(size_t currentIdx) const;
        unsigned maxPriorityChild(unsigned idx);
        void heapifyDown(unsigned idx);
        void heapifyUp(unsigned idx);
        unsigned size() const;
        void updateElem(unsigned idx, const T& elem);
        vector<T> getElems() const;
        void clear();
    private:
        vector<T> elems_;
};

template <typename T>
void PriorityQueue<T>::insert(T e) {
    elems_.push_back(e);
    heapifyUp(elems_.size() - 1);
}

template <typename T>
unsigned PriorityQueue<T>::size() const{ 
    return elems_.size();
}

template <typename T>
T PriorityQueue<T>::remove() {
    T e = elems_.at(0);
    swap(elems_.at(0), elems_.at(elems_.size() - 1));
    elems_.pop_back();
    heapifyDown(0);
    return e;
}

template <typename T>
void PriorityQueue<T>::swap(T& e1, T& e2) {
    T temp = e1;
    e1 = e2;
    e2 = temp;
}

template <typename T>
bool PriorityQueue<T>::higherPriority(T e1, T e2) {
    return e1 < e2;
}

template <typename T>
unsigned PriorityQueue<T>::maxPriorityChild(unsigned idx) {
    unsigned left_child_idx = 2 * idx + 1;
    unsigned right_child_idx = 2 * idx + 2;
    if (left_child_idx >= elems_.size()) {
        return right_child_idx;
    } else if (right_child_idx >= elems_.size()) {
        return left_child_idx;
    }
    T left_child = elems_.at(2 * idx + 1);
    T right_child = elems_.at(2 * idx + 2);
    if (higherPriority(left_child, right_child)) {
        return left_child_idx;
    } else {
        return right_child_idx;
    }
}

template <typename T>
bool PriorityQueue<T>::hasAChild(size_t idx) const {
    if (2 * idx + 1 >= elems_.size() && 2 * idx + 2 >= elems_.size()) {
        return false;
    }
    return true;
}

template <typename T>
void PriorityQueue<T>::heapifyDown(unsigned idx) {
    if (!hasAChild(idx)) {
        return;
    }
    size_t minChild = maxPriorityChild(idx);
    if (!higherPriority(elems_.at(idx), elems_.at(minChild))) {
        swap(elems_.at(idx), elems_.at(minChild));
        heapifyDown(minChild);
    }
}

template <typename T>
void PriorityQueue<T>::heapifyUp(unsigned idx) {
    if (idx == 0)
        return;
    unsigned parentIdx = floor((idx-1)/2);
    if (higherPriority(elems_[idx], elems_[parentIdx])) {
        swap(elems_[idx], elems_[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <typename T>
vector<T> PriorityQueue<T>::getElems() const {
    return elems_;
}

template <class T>
void PriorityQueue<T>::updateElem(unsigned idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    if (idx >= elems_.size()) {
        return;
    } 
    elems_[idx] = elem;
    heapifyUp(idx);
    heapifyDown(idx);
}

template <typename T>

void PriorityQueue<T>::clear() {
    while (elems_.size() > 0) {
        elems_.pop_back();
    }
}