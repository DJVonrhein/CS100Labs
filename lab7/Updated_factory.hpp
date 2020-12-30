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
	Factory() {}
	Base* parse(int argc, char** argv) {

            Base *tempVal = nullptr;
            Base *left = new Op(atof(input[1]));
            for(int i = 2; i < length - 1; i++) {
                if (input[i][0] == '+')
                    tempVal = new Add(left, new Op(atof(input[i + 1])));
                else if (input[i][0] == '*')
                    tempVal = new Mult(left, new Op(atof(input[i + 1])));
                else if (input[i][0] == '*' && input[i][1] == '*')
                    tempVal = new Pow(left, new Op(atof(input[i + 1])));
                else if (input[i][0] == '-')
                    tempVal = new Sub(left, new Op(atof(input[i + 1])));
                else if (input[i][0] == '/')
                    tempVal = new Div(left, new Op(atof(input[i + 1])));
                else {
                    return nullptr;
                }
                left = tempVal;
                i++;
            }
            return tempVal;
	
	}
};
