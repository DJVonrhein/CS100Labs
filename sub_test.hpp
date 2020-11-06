#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"


TEST(SubTest, SubMockEvalNeg){
	SubMockNeg* test = new SubMockNeg(); 
	EXPECT_EQ(test->evaluate(), x);
}

TEST(SubTest, SubMockEvalZero){
	SubMockZero* test = new SubMockZero();
	EXPECT_EQ(test->evaluate(), x);
}

TEST(SubTest, SubMockEvalDouble){
	SubMockDouble* test = new SubMockDouble();
	EXPECT_EQ(test->evaluate(), x);
}

TEST(SubTest, SubMockStringifyNeg){
	SubMockNeg* test = new SubMockNeg();
	EXPECT_EQ(test->evaluate(), x);
}

TEST(SubTest, SubMockStringifyZero){
	SubMockZero* test = new SubMockZero();
	EXPECT_EQ(test->evaluate(), x);
}

TEST(SubTest, SubMockStringifyDouble){
	SubMockDouble* test = new SubMockDouble();
	EXPECT_EQ(test->evaluate(), x);
}	




#endif
