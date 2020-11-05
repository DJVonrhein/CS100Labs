#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNeg) {
    Op* test = new Op(-5);
    EXPECT_EQ(test->evaluate(), -5);
}

TEST(OpTest, OpEvaluatePosDouble) {
    Op* test = new Op(3.5);
    EXPECT_EQ(test->evaluate(), 3.5);
}

TEST(OpTest, OpEvaluateNegDouble) {
    Op* test = new Op(-9.4);
    EXPECT_EQ(test->evaluate(), -9.4);
}

TEST(OpTest, OpEvaluateMockPos){
    SevenOpMock* test= new SevenOpMock();
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(OpTest, OpEvaluateMockZero){
    ZeroOpMock* test= new ZeroOpMock();
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(OpTest, OpEvaluateMockNeg){
    NegOpMock* test= new NegOpMock();
    EXPECT_EQ(test->evaluate(), -1.0);
}


TEST(OpTest, OpStringifyPos) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpStringifyNeg) {
    Op* test = new Op(-5);
    EXPECT_EQ(test->stringify(), "-5.000000");
}

TEST(OpTest, OpStringifyPosDouble) {
    Op* test = new Op(3.5);
    EXPECT_EQ(test->stringify(), "3.500000");
}

TEST(OpTest, OpMockStringifyPos) {
    SevenOpMock* test = new SevenOpMock();
    EXPECT_EQ(test->stringify(), "7.5");
}

TEST(OpTest, OpMockStringifyZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_EQ(test->stringify(), "0.0");
}

TEST(OpTest, OpMockStringifyNeg) {
    NegOpMock* test = new NegOpMock();
    EXPECT_EQ(test->stringify(), "-1.0");
}


#endif 
