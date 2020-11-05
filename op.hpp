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




//MOCK for positive double return val
class SevenOpMock: public Base {
    public:
        SevenOpMock() : Base() { }

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

//MOCK for negative double return val
class NegOpMock: public Base {
    public:
        NegOpMock() : Base() { }

        virtual double evaluate() { return -1.0; }
        virtual std::string stringify() { return "-1.0"; }
};

//MOCK for zero return val
class ZeroOpMock: public Base {
    public:
        ZeroOpMock() : Base() { }

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.0"; }
};
#endif //__OP_HPP__
