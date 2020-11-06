#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

Test(AddTest, AddMockPositiveTest) {
	Add* test = new Add(2, 3);
	EXPECT_EQ(test->evaluate(), 5);
}

Test(AddTest, AddMockNegativeTest) {
	Add* test = new Add(-2, -3);
	EXPECT_EQ(test->evaluate(), -5);
}

Test(AddTest, AddMockOnePosOneNeg) {
	Add* test = new Add(-5, 6);
	EXPECT_EQ(test->evaluate(), 1);
}

Test(AddTest, AddZeroAndNeg) {
	Add* test = new Add(0, -3);
	EXPECT_EQ(test->evaluate(), -3);
}

Test(AddTest, AddZeroAndPos) {
	Add* test = new Add(3, 0);
	EXPECT_EQ(test->evaluate(), 3);
}
