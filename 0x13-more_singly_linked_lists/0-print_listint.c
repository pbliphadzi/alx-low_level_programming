#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint(const listint_t *h)
{
  size_t numnodes = 0;

    while (h)
    {
        printf("%d\n", h->n);
        numnodes++;
        h = h->next;
    }

    return numnodes;
}

