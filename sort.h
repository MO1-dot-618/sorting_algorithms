#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t n, int lo, int hi);
int lomuto_partition(int *array, size_t n, int lo, int hi);
void shell_sort(int *a, size_t n);
int hoare_partition(int *array, size_t n, int lo, int hi);
void hoare_sort(int *array, size_t n, int lo, int hi);
void quick_sort_hoare(int *array, size_t size);

#endif
