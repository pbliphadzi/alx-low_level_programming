#include <stddef.h>
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint_end - add node at end of list
 * @head: argument 1
 * @n: argument 2
 * Return: returns a node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node = malloc(sizeof(dlistint_t));
	dlistint_t *temporary = *head;

	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL;
	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}
	while (temporary->next != NULL)
		temporary = temporary->next;

	temporary->next = node;
	node->prev = temporary;
	return (node);
}