#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 *
 * @head: A pointer to the head of the list_t list.
 *
 * Description: Frees a list_t list, freeing each node
 *              and its contents.
 */
void free_list(list_t *head)
{
    list_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current->str);
        free(current);
    }
}

