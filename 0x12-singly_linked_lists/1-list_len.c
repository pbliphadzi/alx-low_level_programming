#include <stdlib.h>
#include "lists.h"

/**
 * list_len - gets the number of nodes
 *
 * @h: pointer to the head (first node)
 *
 * Return: number of nodes
*/

size_t list_len(const list_t *h)
{
	size_t nodecounter = 0;

	while (h != NULL)
	{
		switch (h != NULL)
		{
			case 1:
				nodecounter++;
				h = h->next;
				break;
			case 0:
				break;
		}
	}

	return (nodecounter);
}

