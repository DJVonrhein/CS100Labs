#include "ListContainer.hpp"

ListContainer::ListContainer(){
	sort_function = nullptr;
}
ListContainer::ListContainer(Sort* function){
        sort_function = function;
}

void ListContainer::set_sort_function(Sort* function){
	sort_function = function;
}

void ListContainer::add_element(Base* element){
	l.push_back(element);
}


void ListContainer::print(){
	if(l.empty())
		return;

	cout << l.front()->stringify();
	
	list<Base*>::iterator i = l.begin();
	advance(i, 1);
	while (i != l.end()){
		cout << ", " << (*i)->stringify();
		advance(i, 1);
	}
}

void ListContainer::sort(){
	sort_function->sort(this);
}

void ListContainer::swap(int i, int j){
	list<Base*>::iterator itr1 = l.begin();
	list<Base*>::iterator itr2 = l.begin();
	advance(itr1, i);
        advance(itr2, j);
	iter_swap(itr1,itr2);
}

Base* ListContainer::at(int i){
	list<Base*>::iterator itr = l.begin();
	advance(itr,i);

	return *itr;
}

int ListContainer::size(){
	return l.size();
}
