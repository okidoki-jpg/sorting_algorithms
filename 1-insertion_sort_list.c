#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 * @list: pointer to the doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;

	while (node)
	{
		while (node->prev && node->n < node->prev->n)
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;

			if (node->prev)
				node->prev->next = node;
			else
				*list = node;

			print_list(*list);
		}
		node = node->next;
	}
}
