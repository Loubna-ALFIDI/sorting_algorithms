#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * @low: lowest index of array
 * @high: highest index of array
 * Return: Nothing
 */
int hoare_partition(int *array, int size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * @low: lowest index of array
 * @high: highest index of array
 * Return: Nothing
 **/
void quicksort_hoare(int *array, int size, int low, int high)
{
	int p = hoare_partition(array, size, low, high);

	if (low < p - 1)
		quicksort_hoare(array, size, low, p - 1);

	if (p < high)
		quicksort_hoare(array, size, p, high);
}

/**
 * quick_sort_hoare - recursive helper function for quick_sort
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quicksort_hoare(array, size, 0, size - 1);
}
