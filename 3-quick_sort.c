#include "sort.h"

/**
 * quick_sort - Sort an array of integers in ascending order
 *                  using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, (int)size - 1);
}

/**
 * lomuto_sort - Recursive function - Lomuto algorithm
 * @array: An array of integers
 * @n: size of array
 * @lo: lowest index of the array
 * @hi: highest index of the array
 */
void lomuto_sort(int *array, size_t n, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;
	p = lomuto_partition(array, n, lo, hi);
	lomuto_sort(array, n, lo, p - 1);
	lomuto_sort(array, n, p + 1, hi);
}

/**
 * lomuto_partition - Lomuto algorithm
 * @array: An array of integers
 * @n: size of array
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * Return: pivot
 */
int lomuto_partition(int *array, size_t n, int lo, int hi)
{
	int pivot = array[hi];
	int temp;
	int j, i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, n);
			}
		}
	}
	i++;
	if (i != hi)
	{
		temp = array[hi];
		array[hi] = array[i];
		array[i] = temp;
		print_array(array, n);
	}
	return (i);
}

