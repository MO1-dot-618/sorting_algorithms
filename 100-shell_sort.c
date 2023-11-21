#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending order
 *                  using the Shell sort algorithm.
 * @a: An array of integers.
 * @n: The size of the array.
 */
void shell_sort(int *a, size_t n)
{
	size_t i, j, gap = 1;
	int temp;

	while (gap < n / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
	for (i = gap; i < n; ++i)
	{
		temp = a[i];
		for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			a[j] = a[j - gap];
		a[j] = temp;
	}
	print_array(a, n);
	gap = (gap - 1) / 3;
	}
}
