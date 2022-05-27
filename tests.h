#ifndef MAIN_CPP_TESTS_H
#define MAIN_CPP_TESTS_H

#include "polynomial.h"
#include "gtest/gtest.h"

std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

typedef Polynomial<10000, 4, 3, 2, 1> gpoly;

TEST(TestName, Subtest_1){
    ASSERT_TRUE(gpoly::Count<5>::result == 6250586);
}

TEST(TestName2, Subtest_2){
    ASSERT_FALSE(gpoly::Count<5>::result == 85);
}

TEST(TestName3, Subtest_3){
    EXPECT_TRUE(gpoly::Count<5>::result == 6250585);
}

TEST(TestName4, Subtest_4){
    //ASSERT_TRUE(gpoly::Count<5>::result == 87);
}

#endif //MAIN_CPP_TESTS_H
