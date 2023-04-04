#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @n: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *n)
{
    size_t counter = 0;

    while (n->next != NULL) {
        n = n->next;
        counter++;
    }

    return counter;
}

