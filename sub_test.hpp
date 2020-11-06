#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"


TEST(SubTest, SubMockEvalNeg){
	SubMockNeg* test = new SubMockNeg(); 
	EXPECT_EQ(test->evaluate(), -1);
}

TEST(SubTest, SubMockEvalZero){
	SubMockZero* test = new SubMockZero();
	EXPECT_EQ(test->evaluate(), 3);
}

TEST(SubTest, SubMockEvalDouble){
	SubMockDouble* test = new SubMockDouble();
	EXPECT_EQ(test->evaluate(), 7.7);
}

TEST(SubTest, SubMockStringifyNeg){
	SubMockNeg* test = new SubMockNeg();
	EXPECT_EQ(test->stringify(), "-4.000000 - -3.000000");
}

TEST(SubTest, SubMockStringifyZero){
	SubMockZero* test = new SubMockZero();
	EXPECT_EQ(test->stringify(), "0.000000 - -3.000000");
}

TEST(SubTest, SubMockStringifyDouble){
	SubMockDouble* test = new SubMockDouble();
	EXPECT_EQ(test->stringify(), "3.500000 - -4.200000");
}	




TEST(SubTest, SubEvalNeg){
	Op* negFive = new Op(-5);
	Op* negFour = new Op(-4);
	Sub* test = new Sub(negFive, negFour);
	EXPECT_EQ(test->evaluate(), -1);
}

TEST(Subtest, SubEvalZero){
	Op* zero = new Op(0);
	Op* negOne = new Op(-1);
	Sub *test = new Sub(zero, negOne);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(Subtest, SubEvalDouble){
        Op* three = new Op(3.4);
        Op* four = new Op(4.6);
        Sub *test = new Sub(three, four);
        EXPECT_DOUBLE_EQ(test->evaluate(), -1.2);
}




#endif
