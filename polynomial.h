#include <iostream>
#include <type_traits>

template<int X, int Degree>
struct Power {
    constexpr static int result = X * Power<X, Degree - 1>::result;

};

template<int X>
struct Power<X, 0> {
    constexpr static int result = 1;
};

template<int... Coefficients>
struct Polynomial {
    template<int X, int P, int First, int... Other>
    struct For {
        constexpr static int result = First * Power<X, P>::result + For<X, P - 1, Other...>::result;
    };

    template<int X, int Coefficient_>
    struct For <X, 0, Coefficient_> {
        constexpr static int result = Coefficient_ * Power<X, 0>::result;
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