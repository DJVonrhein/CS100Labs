#include "gtest/gtest.h"

#include "VectorContainer.cpp"
#include "op.hpp"

TEST(VectorContainerTestSet, addOneElement) {
	// Setup the elements under test
	Op* seven = new Op(7);
	VectorContainer* test_container = new VectorContainer();

	// Exercise some functionality of the test elements
	test_container->add_element(seven);
	
	// Assert that the container has at least a single element
	// otherwise we are likely to cause a segfault when accessing
	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTestSet, addTwoElements) {
	Op* three = new Op(-3);
	Op* zero = new Op(0);
        VectorContainer* test_container = new VectorContainer();
	test_container->add_element(three);
	test_container->add_element(zero);

	ASSERT_EQ(test_container->size(), 2);
	EXPECT_EQ(test_container->at(1)->evaluate(), 0);
}

TEST(VectorContainerTestSet, SwapTwoElements) {
        Op* three = new Op(-3);
        Op* zero = new Op(0);
        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(three);
        test_container->add_element(zero);
	test_container->swap(0, 1);

        ASSERT_EQ(test_container->size(), 2);
        EXPECT_EQ(test_container->at(1)->evaluate(), -3);
}

TEST(VectorContainerTestSet, PrintPosElement) {
        Op* three = new Op(3);
        Op* zero = new Op(0);
        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(three);
        test_container->add_element(zero);

        ASSERT_EQ(test_container->size(), 2);
        testing::internal::CaptureStdout();
        test_container->print();
        string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "3.000000, 0.000000");
}

TEST(VectorContainerTestSet, PrintNegElement) {       
        Op* three = new Op(-3);
        Op* zero = new Op(0);
        VectorContainer* test_container = new VectorContainer();
        test_container->add_element(three);
        test_container->add_element(zero);

        ASSERT_EQ(test_container->size(), 2);
	testing::internal::CaptureStdout();
	test_container->print();
	string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "-3.000000, 0.000000");
}

