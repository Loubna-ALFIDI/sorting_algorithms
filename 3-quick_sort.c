#include "sort.h"

/**
 * swap_array - swap two elements in an array
 * @array: array of integers
 * @i: index of first element
 * @j: index of second element
 * Return: void
 */

void swap_array(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void quick_sort_recursive(int *array, int left, int right, size_t size)
{
    int i, j, y;

    j = left - 1;
    y = array[right];
    for (i = left; i < right; i++)
    {
        if (array[i] < y)
       {
            j++;
            swap_array(array, j, i);
            if (j != i)
                print_array(array, size);
       }
    }
    if (array[right] < array[j + 1])
    {
        swap_array(array, j + 1, right);
        print_array(array, size);
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
