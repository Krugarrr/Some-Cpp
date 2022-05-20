#include <iostream>
#include "tests.h"


int main(int argc, char* argv[]) {

    Polynomial<3, 2, 1> p;
    std::cout << p << std::endl;

    std::cout << Polynomial<3, 2, 1>::Count<5>::result << std::endl;

    //static_assert(gpoly::Count<5>::result == 86, "False");
    ::testing::InitGoogleTest(& argc, argv);
    return RUN_ALL_TESTS();
}
