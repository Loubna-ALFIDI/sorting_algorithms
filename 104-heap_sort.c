#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: Nothing
 **/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * ma_heapify - sorts an array of integers in ascending order
 * @array: array of integers
 * @i: index of first element
 * @size: size of array
 * @len: length of array
 * Return: Nothing
 **/

void ma_heapify(int *array, size_t size, int i, size_t len)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)len && array[left] > array[max])
		max = left;

	if (right < (int)len && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		ma_heapify(array, size, max, len);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2 || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		ma_heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		ma_heapify(array, size, 0, i);
	}
}
