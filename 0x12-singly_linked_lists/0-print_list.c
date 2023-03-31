#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * print_list - prints the elements of a singly linked list
 * @h: the list
 * Return: the number of elements in list
*/

size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		switch(h->str == NULL) 
		{
			case 1: 
				printf("%s %s\n", "[0]", "(nil)");
				break;
			case 0:
				printf("[%lu] %s\n", strlen(h->str), h->str);
				break;
		}
		h = h->next;
		n++;
	}
	return (n);
}

