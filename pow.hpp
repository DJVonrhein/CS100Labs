#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>

class Pow : public Base {
    public:
        Pow(Base* l, Base* r) : Base() {lhs = l; rhs = r; }
        virtual double evaluate() {
		return pow(lhs->evaluate(), rhs->evaluate()); 
	}       
	 virtual std::string stringify() { return (lhs->stringify() + " ** " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

#endif
