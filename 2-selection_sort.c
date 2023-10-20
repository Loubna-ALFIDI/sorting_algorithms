#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, temp;

	if (size < 2 || !array)
		return;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		for (j = i + 1; j < size - 1 + 1; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != (int)i) 
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		i++;
	}
}
