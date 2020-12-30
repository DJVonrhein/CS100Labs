#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double val) : Base() {value = val; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
	Base* get_right() { return nullptr; }
	Base* get_left() { return nullptr; }
	Iterator* create_iterator() {
	    return  new NullIterator(this);
	}
	void accept(CountVisitor* vis) { vis->visit_op(); } 
    private:
	double value;
};

#endif
