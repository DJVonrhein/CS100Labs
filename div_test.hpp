#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "div.hpp"

TEST(DivTest, EvalDivBothNeg)
	Op* lhs = new Op(-2);
	Op* rhs = new Op(-4);
	Div* test = new Div(lhs, rhs);
	EXPECT_DOUBLE_EQ(test->evaluate(), 0.5);
}

TEST(DivTest, EvalDivDouble)
        Op* lhs = new Op(3);
        Op* rhs = new Op(-4.5);
        Div* test = new Div(lhs, rhs);
        EXPECT_DOUBLE_EQ(test->evaluate(), -0.66);
}

TEST(DivTest, EvalDivZeroBySomething)
        Op* lhs = new Op(0);
        Op* rhs = new Op(-4);
        Div* test = new Div(lhs, rhs);
        EXPECT_DOUBLE_EQ(test->evaluate(), 0);
}

TEST(DivTest, StringifyDivBothNeg)
        Op* lhs = new Op(-2);
        Op* rhs = new Op(-4);
        Div* test = new Div(lhs, rhs);
        EXPECT_EQ(test->stringify(), "-2.000000 / -4.000000");
}

TEST(DivTest, StringifyDivByDouble)
        Op* lhs = new Op(0);
        Op* rhs = new Op(1.98);
        Div* test = new Div(lhs, rhs);
        EXPECT_EQ(test->stringify(), "0.000000 / 1.980000");
}

#endif

