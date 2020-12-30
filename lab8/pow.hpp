#ifndef __POW_HPP__
#define __POW_HPP__

#include "iterator.hpp"
#include "base.hpp"
#include <cmath>
#include "visitor.hpp"
#include "op.hpp"

class Pow : public Base {
    public:
        Pow(Base* l, Base* r) : Base() {lhs = l; rhs = r; }
        virtual double evaluate() {
		return pow(lhs->evaluate(), rhs->evaluate()); 
	}       
	virtual std::string stringify() { return (lhs->stringify() + " ** " + rhs->stringify()); }
	Iterator* create_iterator() {
            return  new BinaryIterator(this);
        }
	Base* get_left() { return lhs; }
        Base* get_right() { return rhs; }
	void accept(CountVisitor* vis) { vis->visit_pow(); }
    private:
        Base* lhs;
        Base* rhs;
};

#endif
