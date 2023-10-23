#include "sort.h"

void quick_sort_recursive(int *array, int left, int right, size_t size)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = array[(left + right) / 2];

    while (i <= j)
    {
        while (array[i] < x && i < right)
            i++;
    
        while (array[j] > x && j > left)
            j--;
        
        if (i <= j)
        {
            y = array[i];
            array[i] = array[j];
            array[j] = y;
            i++;
            j--;
            print_array(array, size);
        }
    }

    if (j > left)
        quick_sort_recursive(array, left, j, size);
    
    if (i < right)
        quick_sort_recursive(array, i, right, size);
    
}

void quick_sort(int *array, size_t size)
{
    if (size < 2 || !array)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
