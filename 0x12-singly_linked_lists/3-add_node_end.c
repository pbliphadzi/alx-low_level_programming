#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @head: pointer to the head of the list
 * @str: string to be added as the content of the new node
 *
 * Return: the address of the new element, or NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
    list_t *newnode, *temp;

    newnode = malloc(sizeof(list_t));
    if (newnode == NULL)
        return (NULL);

    newnode->str = strdup(str);
    if (newnode->str == NULL)
    {
        free(newnode);
        return (NULL);
    }

    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    return (newnode);
}

