#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head pointer to NULL.
 * @head: Pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
  listint_t *curr;

  if (head == NULL)
    return;

  while (*head)
  {
    curr = *head;
    *head = (*head)->next;
    free(curr);
  }

  *head = NULL;
}

