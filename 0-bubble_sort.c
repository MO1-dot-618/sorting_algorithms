#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order
 * @array: An array of integers to sort
 * @n: The size of the array
 */
void bubble_sort(int *array, size_t n)
{
	size_t i, size = n;
	int temp, swap = 1;

	if (array == NULL || size < 2)
		return;

	while (swap == 1)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
				print_array(array, n);
			}
		}
		size--;
	}
}
