#include "sort.h"

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 *                  using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, (int)size - 1);
}

/**
 * hoare_sort - Recursive function - Hoare algorithm
 * @array: An array of integers
 * @n: size of array
 * @lo: lowest index of the array
 * @hi: highest index of the array
 */
void hoare_sort(int *array, size_t n, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;
	p = hoare_partition(array, n, lo, hi);
	hoare_sort(array, n, lo, p);
	hoare_sort(array, n, p + 1, hi);
}

/**
 * hoare_partition - Hoare algorithm
 * @array: An array of integers
 * @n: size of array
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * Return: pivot
 */
int hoare_partition(int *array, size_t n, int lo, int hi)
{
	int pivot = array[hi];
	int temp;
	int j = hi + 1;
	int i = lo - 1;

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

		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
		print_array(array, n);
	}
}
