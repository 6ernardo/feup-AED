#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    vector<int> values={5, 3, 7, 4, 8};
    EXPECT_EQ(3,FunSearchProblem::facingSun(values));
}

TEST(test, squareR){
    int num=25;
    EXPECT_EQ(5,FunSearchProblem::squareR(num));

    num=10;
    EXPECT_EQ(3, FunSearchProblem::squareR(num));

    num=50;
    EXPECT_EQ(7, FunSearchProblem::squareR(num));
}

TEST(test, missingvalue){
    vector<int> values={5, 3, 7, 4, 8};
    EXPECT_EQ(1,FunSearchProblem::smallestMissingValue(values));

    values={1,-4,0 ,2 ,6};
    EXPECT_EQ(3,FunSearchProblem::smallestMissingValue(values));

    values={-4, -2, 0, -6};
    EXPECT_EQ(0,FunSearchProblem::smallestMissingValue(values));

}

TEST(test, minPages){

}
