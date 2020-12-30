#include "gtest/gtest.h"

#include "ListContainer.cpp"
#include "op.hpp"

TEST(ListContainerTestSet, addOneElement) {
	//Setup the elements under test
	Op* seven = new Op(7);
	ListContainer* test_container = new ListContainer();
	
	// Exercise some functionality of the test elements
	test_container->add_element(seven); 					
	// Assert that the container has at least a single element
	//  otherwise we are likely to cause a segfault when accessing
	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}
TEST(ListContainerTestSet, addTwoElements) {
	Op* three = new Op(-3);
	Op* zero = new Op(0);
        ListContainer* test_container = new ListContainer();
	test_container->add_element(three);
	test_container->add_element(zero);

	ASSERT_EQ(test_container->size(), 2);
	EXPECT_EQ(test_container->at(1)->evaluate(), 0);
}

TEST(ListContainerTestSet, SwapTwoElements) {
        Op* three = new Op(-3);
        Op* zero = new Op(0);
        ListContainer* test_container = new ListContainer();
        test_container->add_element(three);
        test_container->add_element(zero);
	test_container->swap(0, 1);

        ASSERT_EQ(test_container->size(), 2);
        EXPECT_EQ(test_container->at(1)->evaluate(), -3);
}

TEST(ListContainerTestSet, PrintPosElement) {
        Op* three = new Op(3);
        Op* zero = new Op(0);
        ListContainer* test_container = new ListContainer();
        test_container->add_element(three);
        test_container->add_element(zero);

        ASSERT_EQ(test_container->size(), 2);
        testing::internal::CaptureStdout();
        test_container->print();
        string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "3.000000, 0.000000");
}

TEST(ListContainerTestSet, PrintNegElement) {       
        Op* three = new Op(-3);
        Op* zero = new Op(0);
        ListContainer* test_container = new ListContainer();
        test_container->add_element(three);
        test_container->add_element(zero);

        ASSERT_EQ(test_container->size(), 2);
	testing::internal::CaptureStdout();
	test_container->print();
	string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "-3.000000, 0.000000");
}
