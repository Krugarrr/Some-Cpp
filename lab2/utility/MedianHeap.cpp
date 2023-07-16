#include "MedianHeap.h"

bool MedianHeap::is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

void MedianHeap::push(double value) {
    if(max_heap.empty()){
        max_heap.push(value);
    }
    else {
        if(value > max_heap.top() or is_equal(value, max_heap.top())) {
            min_heap.push(value);
        }
        else {
            max_heap.push(value);
        }
    }

    if (max_heap.size() - min_heap.size() == 2) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
    else if (min_heap.size() - max_heap.size() == 2) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

double MedianHeap::median() {
    if (max_heap.size() == min_heap.size()) {
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
    else if (max_heap.size() > min_heap.size()) {
        return max_heap.top();
    }
    else if (max_heap.size() < min_heap.size()) {
        return min_heap.top();
    }
}

int MedianHeap::size() {
    if (max_heap.size() == min_heap.size()) {
        return max_heap.size();
    }
    else {
        return max_heap.size() + min_heap.size();
    }
}