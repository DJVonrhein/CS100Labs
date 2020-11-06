#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"

TEST(AddTest, AddMockPositiveTest) {
	Op* two = new Op(2);
	Op* three = new Op(3);
	Add* test = new Add(two, three);
	EXPECT_EQ(test->evaluate(), 5);
}

TEST(AddTest, AddMockNegativeTest) {
	Op* negThree = new Op(-3);
	Op* negTwo = new Op(-2);
	Add* test = new Add(negThree, negTwo);
	EXPECT_EQ(test->evaluate(), -5);
}

TEST(AddTest, AddMockOnePosOneNeg) {
	Op* negFive = new Op(-5);
	Op* six = new Op(6);
	Add* test = new Add(negFive, six);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(AddTest, AddZeroAndNeg) {
	Op* zero = new Op(0);
	Op* negThree = new Op(-3);
	Add* test = new Add(zero, negThree);
	EXPECT_EQ(test->evaluate(), -3);
}

TEST(AddTest, AddZeroAndPos) {
	Op* three = new Op(3);
	Op* zero = new Op(0);
	Add* test = new Add(three, zero);
	EXPECT_EQ(test->evaluate(), 3);
}

#endif
