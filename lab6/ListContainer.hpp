#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "container.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include <list>
using namespace std;


class ListContainer : public Container {
	private:
		list<Base*> l;
	public:
		ListContainer();
		ListContainer(Sort* function);
		void set_sort_function(Sort* function);
		virtual void add_element(Base* element);
		virtual void print();
		virtual void sort();
		virtual void swap(int i, int j);
		virtual Base* at(int i);
		virtual int size();		
};

#endif
