#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(PowTest, NegBase){
	Op* base = new Op(-3);
	Op* exp = new Op(5);
	Pow* test = new Pow(base, exp);
	EXPECT_EQ(test->evaluate(), -273)
}

TEST(PowTest, ZeroBase){
        Op* base = new Op(0);
        Op* exp = new Op(3);
        Pow* test = new Pow(base, exp);
        EXPECT_EQ(test->evaluate(), 0)
}

TEST(PowTest, NegExp){
        Op* base = new Op(4);
        Op* exp = new Op(-2);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 0.0625)
}

TEST(PowTest, DoubleBase){
        Op* base = new Op(1.5);
        Op* exp = new Op(2);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 2.25)
}

TEST(PowTest, DoubleExp){
        Op* base = new Op(4);
        Op* exp = new Op(2.5);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 32)
}




