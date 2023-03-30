#ifndef LIST_H
#define LIST_H
/* File: List.h
 * description : Header file containing prototypes for all functions used in the 0x12. C - Singly linked lists directory
 */

#include <stdarg.h>
#include <stdlib.h> 

/* If we have malloc(), stdlib.h will be needed */
/* struct list_s - single line list template */


typedef struct list
{
	char *str;
	unsigned int len;
	struct list *next;
} list_t;

#endif
