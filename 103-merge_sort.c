#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @tmp: temporary array
 * @left: lowest index of array
 * @right: highest index of array
 * @mid: middle index of array
 * Return: Nothing
*/
void mergeing(int *array, int *tmp, size_t left, size_t mid,
		size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
			tmp[k] = array[i++];
		else
			tmp[k] = array[j++];
	}
	while (i < mid)
		tmp[k++] = array[i++];
	while (j < right)
		tmp[k++] = array[j++];
	for (i = left, k = 0; i < right; i++)
		array[i] = tmp[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - sorts an array of integers in ascending order
 * @array: array of integers
 * @tmp: temporary array
 * @left: lowest index of array
 * @right: highest index of array
 * Return: Nothing
 */
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, tmp, left, mid);
		merge_sort_recursive(array, tmp, mid, right);
		mergeing(array, tmp, left, mid, right);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_ar;

	if (array == NULL || size < 2)
		return;

	tmp_ar = malloc(sizeof(int) * size);
	if (tmp_ar == NULL)
		return;

	merge_sort_recursive(array, tmp_ar, 0, size);

	free(tmp_ar);
}
