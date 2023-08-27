#include <stddef.h>
#include <stdio.h>
#include "lists.h"

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cur = head;
	unsigned int count = 0;
	while (cur != NULL)
	{
		if (count == index)
		{
			return (cur);
		}
	cur = cur->next;
	count++;
	}
	return (NULL);
}