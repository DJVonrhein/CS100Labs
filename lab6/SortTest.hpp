#ifndef _SORT_TEST_HPP_
#define _SORT_TEST_HPP_

#include "gtest/gtest.h"
#include <random>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "sort.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "container.hpp"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "base.hpp"

using namespace std;

//BubbleSort Test

TEST(SortTest, BubbleSortTest) {
	Op* six = new Op(6);
	Op* four = new Op(4);
	Mult* Tree1 = new Mult(six, four);

	Op* two = new Op(2);
	Op* five = new Op(5);
	Add* Tree2 = new Add(two, five);

	Op* nine = new Op(9);
	Op* three = new Op(3);
	Sub* Tree3 = new Sub(nine, three);

	Div* Tree4 = new Div(two, two);

	VectorContainer* container = new VectorContainer();
	container->add_element(Tree1);
	container->add_element(Tree2);
	container->add_element(Tree3);
	container->add_element(Tree4);

	ASSERT_EQ(container->size(), 4);
	EXPECT_EQ(container->at(0)->evaluate(), 24);
	EXPECT_EQ(container->at(1)->evaluate(), 7);
	EXPECT_EQ(container->at(2)->evaluate(), 6);
	EXPECT_EQ(container->at(3)->evaluate(), 1);

	container->set_sort_function(new BubbleSort());
	container->sort();

	ASSERT_EQ(container->size(), 4);   
        EXPECT_EQ(container->at(0)->evaluate(), 1);
        EXPECT_EQ(container->at(1)->evaluate(), 6);
        EXPECT_EQ(container->at(2)->evaluate(), 7);
        EXPECT_EQ(container->at(3)->evaluate(), 24);
}

TEST(SortTest, BubbleSortNegNumber) {
	Op* one = new Op(1);
	Op* seven = new Op(7);
	Mult* Tree1 = new Mult(one, seven);

        Op* NegFive = new Op(-5);
        Op* two = new Op(2);
        Add* Tree2 = new Add(two, NegFive);

        Op* three = new Op(3);
        Sub* Tree3 = new Sub(one, three);

        Op* four = new Op(4);
        Div* Tree4 = new Div(four, two);

        VectorContainer* container = new VectorContainer();
        container->add_element(Tree1);
        container->add_element(Tree2);
        container->add_element(Tree3);
        container->add_element(Tree4);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 7);
        EXPECT_EQ(container->at(1)->evaluate(), -3);
        EXPECT_EQ(container->at(2)->evaluate(), -2);
        EXPECT_EQ(container->at(3)->evaluate(), 2);

        container->set_sort_function(new BubbleSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), -3);
        EXPECT_EQ(container->at(1)->evaluate(), -2);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 7);

}

//selectionsort

TEST(SortTest, SelectionSort) {
        Op* three = new Op(3);
        Op* seven = new Op(7);
        Mult* Tree1 = new Mult(three, seven);

        Op* five = new Op(5);
        Op* two = new Op(2);
        Add* Tree2 = new Add(two, five);

        Op* nine = new Op(9);
        Sub* Tree3 = new Sub(nine, three);

        Op* twenty = new Op(20);
        Div* Tree4 = new Div(twenty, two);

        VectorContainer* container = new VectorContainer();
        container->add_element(Tree1);
        container->add_element(Tree2);
        container->add_element(Tree3);
        container->add_element(Tree4);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 21);
        EXPECT_EQ(container->at(1)->evaluate(), 7);
        EXPECT_EQ(container->at(2)->evaluate(), 6);
        EXPECT_EQ(container->at(3)->evaluate(), 10);

	container->set_sort_function(new SelectionSort());
	container->sort();	

	ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), 6);
        EXPECT_EQ(container->at(1)->evaluate(), 7);
        EXPECT_EQ(container->at(2)->evaluate(), 10);
        EXPECT_EQ(container->at(3)->evaluate(), 21);
}

TEST(SortTest, SelectionSortNegNumbers) {
        Op* three = new Op(3);
        Op* Negseven = new Op(-7);
        Mult* Tree1 = new Mult(three, Negseven);

        Op* Negfive = new Op(-5);
        Op* two = new Op(2);
        Add* Tree2 = new Add(two, Negfive);

        Op* nine = new Op(9);
        Sub* Tree3 = new Sub(nine, three);

        Op* four = new Op(4);
        Div* Tree4 = new Div(four, two);

        VectorContainer* container = new VectorContainer();
        container->add_element(Tree1);
        container->add_element(Tree2);
        container->add_element(Tree3);
        container->add_element(Tree4);

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), -21);
	EXPECT_EQ(container->at(1)->evaluate(), -3);
        EXPECT_EQ(container->at(2)->evaluate(), 6);
        EXPECT_EQ(container->at(3)->evaluate(), 2);

        container->set_sort_function(new SelectionSort());
        container->sort();

        ASSERT_EQ(container->size(), 4);
        EXPECT_EQ(container->at(0)->evaluate(), -21);
        EXPECT_EQ(container->at(1)->evaluate(), -3);
        EXPECT_EQ(container->at(2)->evaluate(), 2);
        EXPECT_EQ(container->at(3)->evaluate(), 6);
}

#endif
