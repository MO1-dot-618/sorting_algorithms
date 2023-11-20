#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, idx, min_idx, temp;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size; idx++)
	{
		min_idx = idx;
		for (i = idx; i < size; i++)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
		}
		if (min_idx != idx)
		{
			temp = array[min_idx];
			array[min_idx] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
