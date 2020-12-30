#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include "op.hpp"

class Rand : public Base {
    public:
        Rand() : Base() {value = rand() % 100; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
	Base* get_left() { return nullptr; }
        Base* get_right() { return nullptr; }
	Iterator* create_iterator() {
	    return new NullIterator(this);
	}
	void accept(CountVisitor* vis) { vis->visit_rand(); }
    private:
        double value;
};

#endif
