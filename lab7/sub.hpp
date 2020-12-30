#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
    public:
        Sub(Base* l, Base* r) : Base() {lhs = l; rhs = r; }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate(); }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
	Base* rhs;
};






class SubMockNeg : public Base {
    public:
        SubMockNeg() : Base() {lhs = new Op( -4); rhs =new Op(-3); }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate(); }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

class SubMockZero : public Base {
    public:
        SubMockZero() : Base() {lhs =new  Op( 0); rhs =new Op(-3); }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate(); }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

class SubMockDouble : public Base {
    public:
        SubMockDouble() : Base() {lhs =new Op(3.5); rhs = new Op(-4.2); }
        virtual double evaluate() { return lhs->evaluate() - rhs->evaluate(); }
        virtual std::string stringify() { return (lhs->stringify() + " - " + rhs->stringify()); }
    private:
        Base* lhs;
        Base* rhs;
};

#endif
