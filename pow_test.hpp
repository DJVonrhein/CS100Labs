#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "pow.hpp"

TEST(PowTest, EvalNegBase){
	Op* base = new Op(-3);
	Op* exp = new Op(5);
	Pow* test = new Pow(base, exp);
	EXPECT_EQ(test->evaluate(), -243);
}

TEST(PowTest, EvalZeroBase){
        Op* base = new Op(0);
        Op* exp = new Op(3);
        Pow* test = new Pow(base, exp);
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(PowTest, EvalNegExp){
        Op* base = new Op(4);
        Op* exp = new Op(-2);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 0.0625);
}

TEST(PowTest, EvalDoubleBase){
        Op* base = new Op(1.5);
        Op* exp = new Op(2);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 2.25);
}

TEST(PowTest, EvalDoubleExp){
        Op* base = new Op(4);
        Op* exp = new Op(2.5);
        Pow* test = new Pow(base, exp);
        EXPECT_DOUBLE_EQ(test->evaluate(), 32);
}


TEST(PowTest, StringifyDoubleExp){
        Op* base = new Op(4);
        Op* exp = new Op(2.5);
        Pow* test = new Pow(base, exp);
        EXPECT_EQ(test->stringify(), "4.000000 ** 2.500000");
}

TEST(PowTest, StringifyNegNumbers){
        Op* base = new Op(-4);
        Op* exp = new Op(-2.5);
        Pow* test = new Pow(base, exp);
        EXPECT_EQ(test->stringify(), "-4.000000 ** -2.500000");
}


#endif


