#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.cpp"

class Add : public Base {
	public:
        	Add(Base* l, Base* r) : Base() {lhs = l; rhs = r}}
                virtual double evaluate() {return lhs->evaluate() + rhs->evaluate()}
                virtual std::string stringify() {return (lhs->stringify() + " + " + rhs->stringify()); }
        private:
                Base* lhs;
                Base* rhs;
}

//Mock for two positve numbers adding
class AddMockPositiveTest : public Base {
	public:
		AddMockPositiveTest(Base* l, Base* r) : Base() {lhs = 2; rhs = 3}
		virtual double evaluate() { return 5 }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }

	private:
		Base* lhs;
		Base* rhs;
}

//Mock for two negative numbers adding
class AddMockNegativesTest : public Base {
       public:
                AddMockNegativeTest(Base* l; Base* r) : Base() {lhs = -2, rhs = -3}
                virtual double evaluate() { return -5 }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
	private:
		Base* lhs;
		Base* rhs;
}

//Mock for one negative and one positive
class AddMockOnePosOneNeg : public Base {
      public: 
                AddMockOnePosOneNeg(Base* l; Base* r) : Base() {lhs = -5, rhs = 6}
                virtual double evaluate() { return 1 }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
      private:
                Base* lhs;
                Base* rhs;
}

//Mock for negative and 0
class AddZeroAndNeg : public Base {
     public:
		AddZeroAndNeg(Base* l, Base* r) : Base() {lhs = 0, rhs = -3}
                virtual double evaluate() {return -3 }
                virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
     private:
		Base* lhs;
		Base* rhs;
}

//Mock for positive and 0
class AddZeroAndPos : public Base {
     public:
		AddZeroAndPos(Base* l, Base* r) : Base() {lhs = 3, rhs = 0}
		virtual double evaluate() {return 3}
		virtual std::string stringify() {return lhs->stringify() + " + " + rhs->stringify(); }
     private:
		Base* lhs;
		Base* rhs;
} 
