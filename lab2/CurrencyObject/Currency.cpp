#include "Currency.h"

Currency::Currency() : value(0.0), previous_value(0.0), request_sum(0.0) {}

const double Currency::getValue() {
    return value;
}

void Currency::add_currency(double new_value) {
    value = new_value;
    previous_value = value;
    request_sum += new_value;
    currencies.push(new_value);
}

double Currency::calc_average() {
    if (currencies.size() == 1) {
        return request_sum;
    }
    return request_sum / currencies.size();
}

double Currency::calc_median() {
    currencies.median();
}

bool Currency::rise() {
    return value > previous_value;
}

bool Currency::fall() {
    return value < previous_value;
}

