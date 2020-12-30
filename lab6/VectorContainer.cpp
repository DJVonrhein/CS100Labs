#include "VectorContainer.hpp"

VectorContainer::VectorContainer(){
        sort_function = nullptr;
}
VectorContainer::VectorContainer(Sort* function){
        sort_function = function;
}

void VectorContainer::set_sort_function(Sort* function){
        sort_function = function;
}

void VectorContainer::add_element(Base* element){
	v.push_back(element);
}


void VectorContainer::print(){
	if(v.empty())
		return;

	cout << v.at(0)->stringify();
	for (int i = 1; i < v.size(); i++){
		cout << ", " << v.at(i)->stringify();
	}
}

void VectorContainer::sort(){
	sort_function->sort(this);
}

void VectorContainer::swap(int i, int j){
	Base* temp = v.at(i);
	v.at(i) = v.at(j);
	v.at(j) = temp;
}

Base* VectorContainer::at(int i){
	return v.at(i);
}

int VectorContainer::size(){
	return v.size();
}
