#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"

TEST(MultTest, TwoNegFac) {
	Op* lhs = new Op(-2.2);
	Op* rhs = new Op(-3);
	Mult* test = new Mult(lhs, rhs);
	EXPECT_DOUBLE_EQ(test->evaluate(), 6.6);
}

TEST(MultTest, MultDouble) {
	Op* lhs = new Op(3);
	Op* rhs = new Op(-2.5);
	Mult* test = new Mult(lhs, rhs);
	EXPECT_DOUBLE_EQ(test->evaluate(), -7.5);
}

TEST(MultTest, MultbyZero) {
	Op* lhs = new Op(0);
	Op* rhs = new Op(8);
	Mult* test = new Mult(lhs, rhs);
	EXPECT_DOUBLE_EQ(test->evaluate(), 0);
}

TEST(MultTest, StringIfBothNeg) {
	Op* lhs = new Op(-2);
	Op* rhs = new Op(-3);
	Mult* test = new Mult(lhs, rhs);
	EXPECT_EQ(test->stringify(), "-2.000000 * -3.000000");
}

TEST(MultTest, StringIfMultZero) {
	Op* lhs = new Op(0);
	Op* rhs = new Op(5);
	Mult* test = new Mult(lhs, rhs);
	EXPECT_EQ(test->stringify(), "0.000000 * 5.000000");
}
#endif
