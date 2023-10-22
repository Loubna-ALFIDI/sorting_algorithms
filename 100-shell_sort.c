#include "sort.h"

void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (size < 2 || !array)
        return;

    for  (gap = 0; gap < size; gap++)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
            {
                array[j] = array[j - gap];
                print_array(array, size);
            }
            array[j] = temp;
        }
    }
}