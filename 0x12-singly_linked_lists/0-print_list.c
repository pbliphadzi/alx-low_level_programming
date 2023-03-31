#include "lists.h"

/**
 * print_list - print elements in a linked list
 *
 * @h: pointer to head of the first node
 *
 * Return: Number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t b = 0;

	while (h)
	{
		if (h->str)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");

		h = h->next;
		b++;
	}

	return (b);
}
