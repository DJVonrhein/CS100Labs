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

//Mock for two positve numbers adding
class AddMockPositiveTest : public Base {
	public:
		AddMockPositiveTest() : Base() {lhs = new Op(2); rhs = new Op(3);}
		virtual double evaluate() { return 5; }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }

	private:
		Base* lhs;
		Base* rhs;
};

//Mock for two negative numbers adding
class AddMockNegativeTest : public Base {
       public:
                AddMockNegativeTest() : Base() {lhs = new Op(-2); rhs = new Op(-3);}
                virtual double evaluate() { return -5; }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
	private:
		Base* lhs;
		Base* rhs;
};

//Mock for one negative and one positive
class AddMockOnePosOneNeg : public Base {
      public: 
                AddMockOnePosOneNeg() : Base() {lhs = new Op(-5); rhs = new Op(6);}
                virtual double evaluate() { return 1; }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
      private:
                Base* lhs;
                Base* rhs;
};

//Mock for negative and 0
class AddZeroAndNeg : public Base {
     public:
		AddZeroAndNeg() : Base() {lhs = new Op(0); rhs = new Op(-3);}
                virtual double evaluate() {return -3; }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
     private:
		Base* lhs;
		Base* rhs;
};

//Mock for positive and 0
class AddZeroAndPos : public Base {
     public:
		AddZeroAndPos(Base* l, Base* r) : Base() {lhs = new Op(3); rhs =new Op( 0);}
		virtual double evaluate() {return 3;}
		virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
     private:
		Base* lhs;
		Base* rhs;
};
#endif 
