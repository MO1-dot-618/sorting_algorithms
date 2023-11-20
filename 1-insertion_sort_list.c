#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm
 * @list: A pointer to the head of a doubly-linked list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *nood, *tmp_next, *tmp_prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		nood = node;
		while (nood->n < nood->prev->n && nood->prev != NULL)
		{
			tmp_next = nood->next;
			nood->next = nood->prev;
			nood->prev->next = tmp_next;
			tmp_prev = nood->prev->prev;
			nood->prev->prev = nood;
			nood->prev = tmp_prev;
			print_list(*list);
		}
		node = node->next;
	}
}
