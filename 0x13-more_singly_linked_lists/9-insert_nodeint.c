#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to a pointer to the head of the list.
 * @idx: Index of the position where the new node should be added. Index starts at 0.
 * @n: Data (n) to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */

void print_diagsums(int *a, int size)
{
  int i, sum1 = 0, sum2 = 0;

  for (i = 0; i < size * size; i++)
  {
    switch (i % (size + 1))
    {
      case 0:
        sum1 += a[i];
        break;
      case size:
        sum2 += a[i];
        break;
      default:
        break;
    }
  }

  printf("%d, %d\n", sum1, sum2);
}

