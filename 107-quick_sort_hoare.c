#include "sort.h"
/**
 * swap_array - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: Nothing
 */
void swap_array(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
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

		swap_array(array, i, j);
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

	if (low < high)
	{
		quicksort_hoare(array, size, low, p - 1);
		quicksort_hoare(array, size, p, high);
	}
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
