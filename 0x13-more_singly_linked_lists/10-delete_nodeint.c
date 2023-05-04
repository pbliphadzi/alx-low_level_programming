#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index in a linked list
 * @head: Pointer to the head node of the list
 * @index: Index of the node to delete
 *
 * Return: 1 if successful, -1 otherwise
 *
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
  listint_t *curr, *pre;
  unsigned int i;

  if (*head == NULL)
    return (-1);

  if (index == 0)
  {
    *head = (*head)->next;
    free(curr);
    return (1);
  }

  pre = *head;
  curr = (*head)->next;

  for (i = 1; i < index; i++)
  {
    if (curr == NULL)
      return (-1);
    pre = curr;
    curr = curr->next;
  }

  pre->next = curr->next;
  free(curr);
  return (1);
}

