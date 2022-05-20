#ifndef MAIN_CPP_TESTS_H
#define MAIN_CPP_TESTS_H

#include "polynomial.h"
#include "gtest/gtest.h"

typedef Polynomial<3, 2, 1> gpoly;

TEST(TestName, Subtest_1){
    ASSERT_TRUE(gpoly::Count<5>::result == 86);
}

TEST(TestName2, Subtest_2){
    ASSERT_FALSE(gpoly::Count<5>::result == 85);
}

TEST(TestName3, Subtest_3){
    EXPECT_TRUE(gpoly::Count<5>::result == 87);
}

TEST(TestName4, Subtest_4){
    //ASSERT_TRUE(gpoly::Count<5>::result == 87);
}

#endif //MAIN_CPP_TESTS_H
