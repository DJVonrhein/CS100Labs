#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"

class Div : public Base {
    public:
        Div(Base* l, Base* r) : Base() {lhs = l; rhs = r; }
        virtual double evaluate() { return lhs->evaluate() / rhs->evaluate(); }
        virtual std::string stringify() { return (lhs->stringify() + " / " + rhs->stringify()); }
	Iterator* create_iterator() {
            return new BinaryIterator(this);
        }
	Base* get_left() { return lhs; }
        Base* get_right() { return rhs; }
	void accept(CountVisitor* vis) { vis->visit_div(); }
    private:
        Base* lhs;
        Base* rhs;
};

#endif

