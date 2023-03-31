#ifndef _LISTS_H
#define _LISTS_H
/* File: List.h
 * description : Header file containing prototypes for all functions used in the 0x12. C - Singly linked lists directory
 */

#include <stdarg.h>
#include <stdlib.h> 

/* If we have malloc(), stdlib.h will be needed */
/* struct list_s - single line list template */


typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list *next;
} list_t;

/* Prototypes for 0x12-singly_linked_lists */

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
