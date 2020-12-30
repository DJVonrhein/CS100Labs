#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double val) : Base() {value = val; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
    private:
	double value;
};

#endif
