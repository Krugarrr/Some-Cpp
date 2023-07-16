#ifndef INC_2LABCPP_MEDIANHEAP_H
#define INC_2LABCPP_MEDIANHEAP_H
#include "../include/simple_include.h"

using std::vector;
using std::greater;
using std::less;

class MedianHeap
{
private:
    std::priority_queue<double> max_heap;
    std::priority_queue<double, vector<double>, greater<double>> min_heap;
    static bool is_equal(double x, double y);

public:
    void push(double value);
    int size();
    double median();
};

#endif //INC_2LABCPP_MEDIANHEAP_H
