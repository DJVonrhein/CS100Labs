#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "container.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include <vector>
using namespace std;


class VectorContainer : public Container {
	private:
		
		vector<Base*> v;
	public:
		VectorContainer();
		VectorContainer(Sort* function);
		void set_sort_function(Sort* function);
		virtual void add_element(Base* element);
		virtual void print();
		virtual void sort();
		virtual void swap(int i, int j);
		virtual Base* at(int i);
		virtual int size();		
};

#endif
