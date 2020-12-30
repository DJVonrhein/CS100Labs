#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "factory.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
	
	Factory* myFactory = new Factory();
	Base* myBase = myFactory->parse(argc, argv);
	
	if(!myBase){
		cout << "incorrect arguments.\n";
		exit(1);
	}
	
	cout << myBase->stringify() << " = " << myBase->evaluate();
	//must return the stringify() and evaluate() of myFactory's tree
	return 0;
}
