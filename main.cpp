#include <iostream>
#include "tests.h"


int main(int argc, char* argv[]) {

    Polynomial<3, 2, 1> p;
    std::cout << p << std::endl;

    std::cout << Polynomial<10000, 4, 3, 2, 1>::Count<5>::result << std::endl;
    std::chrono::steady_clock::steady_clock::time_point t2 = std::chrono::steady_clock::steady_clock::now();
    std::chrono::duration<double> vector_time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "It took me " << vector_time_span.count() << " seconds " << std::endl;
    static_assert(gpoly::Count<5>::result == 6250586, "False");
    ::testing::InitGoogleTest(& argc, argv);
    return RUN_ALL_TESTS();
}
