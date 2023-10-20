#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Doubly linked list to be sorted
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (!current->prev)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = tmp;
	}

}
