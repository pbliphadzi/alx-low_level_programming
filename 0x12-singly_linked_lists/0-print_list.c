#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list
 * Return: number of nodes printed
**/
size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		switch(h->str != NULL)
		{
			case 0:
				printf("[0] (nil)\n");
				break;
			case 1:
				printf("[%u] %s\n", h->len, h->str);
				break;
		}
		h = h->next;
		n++;
	}
	return (n);
}

