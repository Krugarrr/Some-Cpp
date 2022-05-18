#include <iostream>
#include "polynomial.h"

int main() {
    Polynomial<3, 2, 1> p;
    std::cout << Polynomial<3, 2, 1>::Count<5>::result << std::endl;
    std::cout << p;
    return 0;
}
