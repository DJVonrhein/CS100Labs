#include "visitor.hpp"
#include "iterator.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"
#include "gtest/gtest.h"
#include <iostream>

//this test tries counting a tree consisting of one operand. We have to include it twice because we require a dummy with both a left and right Base*.
TEST(IteratorTest, only_ops_test) {
        Op* num1 = new Op(3);
	Op* num2 = new Op(7);
       
        Base* dummy = new Add(num1, num2); //we'll have two ops to account for.

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
		it->current()->accept(visitor);
        	it->next();
        }
        EXPECT_EQ(visitor->op_count(), 2); // Our tree has two ops 
        EXPECT_EQ(visitor->add_count(), 0); // Our add is the dummy - doesn't get counted!
}

// Same test, but using rands 
TEST(IteratorTest, only_rands_test) {
        Rand* num1 = new Rand();
        Rand* num2 = new Rand();

        Base* dummy = new Add(num1, num2); //we'll have two ops to account for.

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }
        EXPECT_EQ(visitor->rand_count(), 2); // Our tree has two ops 
        EXPECT_EQ(visitor->add_count(), 0); // Our add is the dummy - doesn't get counted!
}

/*
TEST(IteratorTest, one_mult_test) {
	Op* num = new Op(4);
	
	Base* dummy = new Mult(num, num);
	
	Iterator* it = new PreorderIterator(dummy);
	CountVisitor* visitor = new CountVisitor();
	it->first();
	while(!it->is_done()) {
		it->current()->accept(visitor);
		it->next();
	}
	EXPECT_EQ(visitor->op_count(), 2);
	EXPECT_EQ(visitor->mult_count(), 0);
}

TEST(IteratorTest, one_div_test) {
        Op* num1 = new Op(14);
	Op* num2 = new Op(2);

        Base* dummy = new Div(num1, num2); //we'll have two num1's to account for.

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }
        EXPECT_EQ(visitor->op_count(), 2); // Our tree has two ops (both are 3s).!
        EXPECT_EQ(visitor->add_count(), 0); // Our add is the dummy - doesn't get counted!
}

TEST(IteratorTest, one_sub_test) {
        Op* num1 = new Op(3);
	Op* num2 = new Op(1);


        Base* dummy = new Sub(num1, num2); //we'll have two num1's to account for.

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }
        EXPECT_EQ(visitor->op_count(), 2); // Our tree has two ops (both are 3s).!
        EXPECT_EQ(visitor->add_count(), 0); // Our add is the dummy - doesn't get counted!
}
*/

TEST(IteratorTest, visit_pow_test) {
	Op* num1 = new Op(3);
	Op* num2 = new Op(7);
	Op* num3 = new Op(2);
	Pow* temp = new Pow(num1, num2);
	Base* dummy = new Add(temp, num3); // there are three ops. 
	
	Iterator* it = new PreorderIterator(dummy);
	
	CountVisitor* visitor = new CountVisitor();
	it->first();
	while (!it->is_done()) {
		it->current()->accept(visitor);
		it->next();
	}
	    
    	EXPECT_EQ(visitor->op_count(), 3);
	EXPECT_EQ(visitor->pow_count(), 1);
	EXPECT_EQ(visitor->add_count(), 0); // again, the add is a dummy so we don't want to see it counted.
}

TEST(IteratorTest, visit_mult_test) {
        Op* num1 = new Op(3);
        Op* num2 = new Op(7);
	Op* num3 = new Op(2);
        Mult* temp = new Mult(num1, num2);
        Base* dummy = new Add(temp, num3); // there are three ops. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 3);
        EXPECT_EQ(visitor->mult_count(), 1);
        EXPECT_EQ(visitor->add_count(), 0); // again, the add is a dummy so we don't want to see it counted.
}

TEST(IteratorTest, visit_div_test) {
        Op* num1 = new Op(3);
        Op* num2 = new Op(7);
 	Op* num3 = new Op(2);   
        Div* temp = new Div(num1, num2);
        Base* dummy = new Add(temp, num3); // there are three ops. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 3);
        EXPECT_EQ(visitor->div_count(), 1);
        EXPECT_EQ(visitor->add_count(), 0); // again, the add is a dummy so we don't want to see it counted.
}

TEST(IteratorTest, visit_sub_test) {
        Op* num1 = new Op(3);
        Op* num2 = new Op(7);
	Op* num3 = new Op(2);
        Sub* temp = new Sub(num1, num2);
        Base* dummy = new Add(temp, num3); //there are three ops. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 3);
        EXPECT_EQ(visitor->sub_count(), 1);
        EXPECT_EQ(visitor->add_count(), 0); // again, the add is a dummy so we don't want to see it counted.
}

TEST(IteratorTest, visit_add_test) {
        Op* num1 = new Op(3);
        Op* num2 = new Op(7);
 	Op* num3 = new Op(2);   
        Add* temp = new Add(num1, num2);
        Base* dummy = new Sub(temp, num3); //there are three ops. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 3);
        EXPECT_EQ(visitor->add_count(), 1);
        EXPECT_EQ(visitor->sub_count(), 0); // this time we made sub a dummy so we don't want to see it counted.
}

//combines two BinaryIterators.
TEST(IteratorTest, multiple_binary_iterators) {
        Op* num1 = new Op(3);
        Op* num2 = new Op(7);
        Op* num3 = new Op(2);
	Op* num4 = new Op(9);
        Add* temp1 = new Add(num1, num2);
	Mult* temp2 = new Mult(num3, num4);
        Base* dummy = new Sub(temp1, temp2); //there are four ops. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 4);
        EXPECT_EQ(visitor->mult_count(), 1);
        EXPECT_EQ(visitor->add_count(), 1);
        EXPECT_EQ(visitor->sub_count(), 0); // this time we made sub a dummy so we don't want to see it counted.
}
//combines four BinaryIterators using both rands and ops.
TEST(IteratorTest, use_all_classes) {
        Rand* rand1 = new Rand();
        Rand* rand2 = new Rand();
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
	Op* op3 = new Op(5);
	Op* op4 = new Op(7);

        Add* temp1 = new Add(rand1, rand2);
        Mult* temp2 = new Mult(op1, op2);
	Div* temp3 = new Div(op3, temp2);
	Pow* temp4 = new Pow(temp1, op4);
        Base* dummy = new Sub(temp3, temp4); //there are four ops, two rands, one pow, one div, one mult, one add, no sub. 

        Iterator* it = new PreorderIterator(dummy);

        CountVisitor* visitor = new CountVisitor();
        it->first();
        while (!it->is_done()) {
                it->current()->accept(visitor);
                it->next();
        }

        EXPECT_EQ(visitor->op_count(), 4);
        EXPECT_EQ(visitor->rand_count(), 2);
	EXPECT_EQ(visitor->mult_count(), 1);
        EXPECT_EQ(visitor->add_count(), 1);
        EXPECT_EQ(visitor->div_count(), 1);
        EXPECT_EQ(visitor->pow_count(), 1);
        EXPECT_EQ(visitor->sub_count(), 0); // this time we made sub a dummy so we don't want to see it counted.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
