#include "lists.h"

int sum_dlistint(dlistint_t *head)
{
	int SUM = 0;

	while (head != NULL)
	{
		SUM += head->n;
		head = head->next;
	}
	return (SUM);
}