#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "container.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sort.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class BubbleSort : public Sort
{
public:
    /* Constructors */
    BubbleSort();

    /* Pure Virtual Functions */
    virtual void sort(Container *container);
};

#endif 
