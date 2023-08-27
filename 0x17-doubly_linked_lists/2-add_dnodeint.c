#include <stddef.h>
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint - add new node to the beginning of list
 * @head: argument 1
 * @n: argument 2
 * Return: returns the address is new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = (*head);
	node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = node
;
	(*head) = node;
	return (node);
}