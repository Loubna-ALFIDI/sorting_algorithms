#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *counting, *sorted;
	int max;
	size_t i;

	if (size < 2 || !array)
		return;

    max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting = malloc(sizeof(int) * (max + 1));
	if (!counting)
		return;

	for (i = 0; i < size; i++)
		counting[array[i]]++;
	for (i = 1; i <= (size_t) max; i++)
		counting[i] += counting[i - 1];
	print_array(counting, max + 1);
	sorted = malloc(sizeof(int) * (max + 1));
	if (!sorted)
	{
		free(counting);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted[counting[array[i]] - 1] = array[i];
		counting[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(counting);
	free(sorted);

}
