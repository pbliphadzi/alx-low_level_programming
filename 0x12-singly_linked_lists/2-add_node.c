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
	list_t *newnode;

	if (head == NULL || str == NULL)
		return (NULL);

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);

	newnode->str = strdup(str);
	if (newnode->str == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->len = strlen(str); /* new line to assign the length (bug fix)*/
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}

