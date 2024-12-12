#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *locator, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	locator = (*list)->next;
	while (locator != NULL)
	{
		temp = locator->prev;

		while (temp != NULL && locator->n < temp->n)
		{
			temp->next = locator->next;

			if (locator->next != NULL)
				locator->next->prev = temp;

			locator->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = locator;

			locator->next = temp;
			temp->prev = locator;

			if (locator->prev == NULL)
				*list = locator;

			print_list(*list);

			temp = locator->prev;
		}
		locator = locator->next;
	}
}
