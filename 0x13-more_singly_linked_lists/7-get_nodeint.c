#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if it does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
  unsigned int y;

  for (y = 0; head != NULL && y < index; y++)
    head = head->next;

  return head;
}
