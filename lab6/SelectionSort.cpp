#include "SelectionSort.hpp"

void SelectionSort::sort(Container *container)
{
    int i, j, first, temp;
    int numLength = container->size();
    for (i = numLength - 1; i > 0; i--)
    {
        first = 0;               // initialize to subscript of first element
        for (j = 1; j <= i; j++) // locate smallest between positions 1 and i.
        {
            if (container->at(j)->evaluate() > container->at(first)->evaluate())
                first = j;
        }
        container->swap(first, i);
    }
    return;
}
