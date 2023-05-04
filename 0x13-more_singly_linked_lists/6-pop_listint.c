#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list and returns its data.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data (d) of the deleted node.
 */
int pop_listint(listint_t **head)
{
  int d;
  listint_t *t;

  if (*head == NULL)
    return 0;

  d = (*head)->d;
  t = *head;
  *head = (*head)->next;
  free(t);

  return d;
}

