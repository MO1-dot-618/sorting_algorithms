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
		while (nood->prev != NULL && nood->n < nood->prev->n)
		{
			tmp_next = nood->next;
			nood->next = nood->prev;
			nood->prev->next = tmp_next;
			if (nood->prev->prev)
				nood->prev->prev->next = nood;
			else
				*list = node;
			tmp_prev = nood->prev->prev;
			nood->prev->prev = nood;
			nood->prev = tmp_prev;
			if (nood->next->next)
				nood->next->next->prev = nood->next;

			print_list(*list);
		}
		node = node->next;
	}
}
