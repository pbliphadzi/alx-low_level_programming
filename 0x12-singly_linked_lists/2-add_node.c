#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node in front of the list
 * @head: pointer to the value of head node
 * @str: poiinter to value string
 * Return: the address of new head node
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

