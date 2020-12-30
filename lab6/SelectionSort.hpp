#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "container.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sort.hpp"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class SelectionSort : public Sort {
public:
    /* Constructors */
    SelectionSort()  { }

    /* Pure Virtual Functions */
    virtual void sort(Container *container);
};

#endif
