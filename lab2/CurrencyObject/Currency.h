#ifndef INC_2LABCPP_CURRENCY_H
#define INC_2LABCPP_CURRENCY_H

#include "../utility/MedianHeap.h"
#include "../include/simple_include.h"

class Currency {
private:
    double value = 0;
    double previous_value = 0;
    double request_sum = 0;
    MedianHeap currencies;

public:
    Currency();

    const double getValue();

    void add_currency(double value_);

    double calc_average();
    double calc_median();

    bool rise();
    bool fall();
};

#endif //INC_2LABCPP_CURRENCY_H
