#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
*/
void bubble_sort(int *array, int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

}