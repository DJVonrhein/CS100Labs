#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"


TEST(RandTest, CheckGTNegative){
	Rand* test = new Rand();
	EXPECT_LT(-1, test->evaluate());
}

TEST(RandTest, CheckLTHundred){
	Rand* test = new Rand();
	EXPECT_LT(test->evaluate(), 100);
}



#endif
