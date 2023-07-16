<<<<<<< lab-6
#include <iostream>
#include <type_traits>
#include <chrono>

/*
 * for any even number n the expression
 * a^n = (a^(n/2))^2 = a^(n/2) * a^(n/2)
 * is true
 *
 * if n is odd we just go to even number (n - 1):
 * a^n = a * a^(n - 1)
 * function of this algorithm will be look like this:
 * int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;

    there will be not more than 2log iterations
    therefore, we have  an algorithm of complexity O(logn)

    So, here's the implementation with templates metaprogramming
 */

template<int X, int Degree, int Y>
struct Power {
    constexpr static int result = std::conditional_t<Degree & 1, Power<X * X, (Degree >> 1), (X * Y)>,
            Power<X * X, (Degree >> 1), Y>>::result;

            // linear function to compare
            //X * Power<X, Degree - 1, 1>::result;

};

template<int X, int Y>
struct Power<X, 0, Y> {
    constexpr static int result = Y;

    //part of linear function to compare
    //1
};

template<int... Coefficients>
struct Polynomial {
    template<int X, int Iteration, int First, int... Other>
    struct For {
        constexpr static int result = First * Power<X, Iteration, 1>::result + For<X, Iteration - 1, Other...>::result;
    };

    template<int X, int Coefficient_>
    struct For <X, 0, Coefficient_> {
        constexpr static int result = Coefficient_ * Power<X, 0, 1>::result;
    };

    template<int X>
    struct Count {
        constexpr static int result = For<X, sizeof... (Coefficients) - 1, Coefficients...>::result;
    };
};


template<int First, int... Other>
static void Print(std::ostream& os, Polynomial<First, Other...> poly){
    if (First > 0){
        os << " + " << First << "x^" << sizeof...(Other);
        Print<Other...>(os, Polynomial<Other...>());
    }
    else if (First < 0) {
        os << " " << First << "x^" << sizeof...(Other);
        Print<Other...>(os, Polynomial<Other...>());
    }
    else
        Print<Other...>(os, Polynomial<Other...>());
}

template<int...>
static void Print(std::ostream& os, Polynomial<> poly){};

template<int First, int... Other>
std::ostream& operator<<(std::ostream& os, Polynomial<First, Other...> poly) {
    os << First << "x^" << sizeof...(Other);
    Print<Other...>(os, Polynomial<Other...>());
    return os;
}
=======
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
>>>>>>> main
