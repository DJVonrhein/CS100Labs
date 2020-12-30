#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
class Add : public Base {
	public:
        	Add(Base* l, Base* r) : Base() {lhs = l; rhs = r;}
                virtual double evaluate() {return lhs->evaluate() + rhs->evaluate();}
                virtual std::string stringify() {return (lhs->stringify() + " + " + rhs->stringify()); }
        private:
                Base* lhs;
                Base* rhs;
};
#endif
