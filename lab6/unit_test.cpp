#include "gtest/gtest.h"
#include "VectorContainer_test.cpp"
#include "ListContainer_test.cpp"
#include "SortTest.hpp"
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
