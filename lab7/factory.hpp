#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "op.hpp"

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctype.h>

using namespace std;

class Factory {
    public:
	Factory() {};
	Base* parse(int argc, char** argv) {

		
		Base *temp = nullptr;
		if(argc == 1)
		    return nullptr;
		
		//checking that operands are numbers
		for(unsigned i = 1; i < argc; i += 2){
		    //std::string s(argv[i]);
		    if(argv[i] == '\0')
			return nullptr;
		    bool decimal_can_be_used = true;
		    bool minus_can_be_used = true;
		    bool number_was_typed = false;
		    for(unsigned j = 0; argv[i][j] != '\0'; ++j){
			if(minus_can_be_used && decimal_can_be_used){	
			    if(!(isdigit(argv[i][j]) || argv[i][j] == '-' || argv[i][j] == '.'))// these are the only allowed characters
			    	return nullptr;
			}
			else if(decimal_can_be_used){
			    if(!(isdigit(argv[i][j]) ||  argv[i][j] == '.'))// these are the only allowed characters
                                return nullptr;
                        }
			else{
			    if(!(isdigit(argv[i][j])))
				return nullptr;
			}
			minus_can_be_used = false;
			if(argv[i][j] == '.')
			    decimal_can_be_used = false;
			if(isdigit(argv[i][j]))
			    number_was_typed = true;
		    }
		    if(!number_was_typed)
			return nullptr;
		}		
		//finished input validation

		Base *left = new Op(atof(argv[1]));
		if(argc == 2)
		    return left;			

                for(int i = 2; i < argc - 1; i += 2)
            	{
                    if (argv[i][0] == '+')
                    	temp = new Add(left, new Op(atof(argv[i + 1])));
                    else if (argv[i][0] == '*' && argv[i][1] == '*')
                	temp = new Pow(left, new Op(atof(argv[i + 1])));
                    else if (argv[i][0] == '*')
                        temp = new Mult(left, new Op(atof(argv[i + 1])));
		    else if (argv[i][0] == '-')
                    	temp = new Sub(left, new Op(atof(argv[i + 1])));
                    else if (argv[i][0] == '/')
                    	temp = new Div(left, new Op(atof(argv[i + 1])));
                    else
               	    {
                    	cout << "Incorrect input";
                    	return nullptr;
                    }
                     left = temp;
		   
            	}
            return left;
	
	}

};

#endif
