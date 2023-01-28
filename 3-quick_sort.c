#include "sort.h"

/**
 * swap - swap integers in an array
 * @array: array to be sorted
 * @a: int to swap
 * @b: int to swap
 *
 * Return: void
 */

void swap(int *array, int a, int b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}


/**
 * partition - splits the array using the Lomuto's partition scheme
 * @array: array to be split
 * @low: start index
 * @high: end index
 * @size: number of elements in array
 *
 * Return: start index for the new partition
 */

int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i, idx = low - 1;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			idx++;
			swap(array, idx, i);
			if (array[idx] != array[i])
				print_array(array, size);
		}
	}

	swap(array, idx + 1, high);
	if (array[++idx] != array[high])
		print_array(array, size);

	return (idx);
}


/**
 * quick_sort_helper - sorts int array in ascending order using the
 * quick sort algorithm
 * @array: array to be sorted
 * @low: start index
 * @high: end index
 * @size: number of elements in array
 *
 * Return: void
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int idx = 0;

	if (low < high)
	{
		idx = partition(array, low, high, size);
		quick_sort_helper(array, low, idx - 1, size);
		quick_sort_helper(array, idx + 1, high, size);
	}
}


/**
 * quick_sort - calls function to sort int array in ascending order
 * quick sort algorithm
 * @array: array to be sorted
 * @size: number of elements in array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
