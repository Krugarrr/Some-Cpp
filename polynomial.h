#ifndef INC_1CPP_LAB_POLYNOMIAL_H
#define INC_1CPP_LAB_POLYNOMIAL_H
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include <iterator>
#include <complex>
#include <numbers>

class Polynomial {
public:
    //construct
    Polynomial();
    Polynomial(int degree_);
    Polynomial(std::initializer_list<int> numbers_);

    //copy
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& original);

    //equality
    friend bool operator==(const Polynomial& left_obj, const Polynomial& right_obj);
    friend bool operator!=(const Polynomial& left_obj, const Polynomial& right_obj);

    //arithmetic
    friend Polynomial operator+(const Polynomial& left_obj, const Polynomial& right_obj);
    Polynomial operator+(const Polynomial& other);
    Polynomial operator+=(Polynomial other);

    Polynomial operator-(const Polynomial& other);
    friend Polynomial operator-(const Polynomial& left_obj, const Polynomial& right_obj);
    Polynomial operator-=(const Polynomial& other);

    Polynomial operator*(const Polynomial& other);
    Polynomial operator*=(const Polynomial& other);
    Polynomial operator*=(int value);
    Polynomial operator*(int value);

    Polynomial operator/(int value);
    Polynomial operator/=(int value);

    //stream
    friend std::ostream& operator<<(std::ostream &os, const Polynomial& object);
    friend Polynomial& operator>>(std::istream &is, Polynomial& object);

    //access
    int operator[](size_t i);
    const int& operator[](size_t i) const;

    //destruct
    ~Polynomial();

    //other
    size_t degree() const;

private:
    std::vector<int> coefficients_;
    void cleaning();
};

typedef std::complex<double> base;

class Fourier {
public:
    friend void fft(std::vector<base>& a, bool invert);
    friend void multiply(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & res);
};

#endif //INC_1CPP_LAB_POLYNOMIAL_H
