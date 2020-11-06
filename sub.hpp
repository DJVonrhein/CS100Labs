#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Sub : public Base {
    public:
        Sub(Base* l, Base* r) : Base() {lhs = l; rhs = r }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate() }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
	Base* rhs;
};






class SubMockNeg : public Base {
    public:
        SubMockNeg() : Base() {lhs = -4; rhs = -3 }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate() }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

class SubMockZero : public Base {
    public:
        SubMockNeg() : Base() {lhs = 0; rhs = -3 }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate() }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

class SubMockDouble : public Base {
    public:
        SubMockDouble() : Base() {lhs = 3.5; rhs = -4.2 }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate() }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};
