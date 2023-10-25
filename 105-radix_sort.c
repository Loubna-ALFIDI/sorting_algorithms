#include "sort.h"

/**
 * count - does counting sort
 * @array: array of integers
 * @size: size of array
 * @p: exponent
 */
void count(int *array, size_t size, int p)
{
	size_t max = 9;
	int *b, *c;
	size_t i;

	b = malloc(sizeof(int) * (max + 1));
	c = malloc(sizeof(int) * (size));

	for (i = 0; i < max + 1; i++)
		b[i] = 0;

	for (i = 0; i < size; i++)
		b[(array[i] / p) % 10] += 1;

	for (i = 1; i < max + 1; i++)
		b[i] += b[i - 1];

	for (i = 0; i < size; i++)
		c[i] = 0;

	for (i = size - 1; i < size; i--)
	{
		c[b[(array[i] / p) % 10] - 1] = array[i];
		b[(array[i] / p) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = c[i];
}

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: array fof integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	for (i = 1; max / i > 0; i *= 10)
	{
		count(array, size, i);
		print_array(array, size);
	}
}
