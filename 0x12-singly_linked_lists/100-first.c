#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * print_sentence - prints sentence from singly linked list
*/

void print_sentence(void)
{
    sentence *head = NULL;
    sentence *sent1 = (sentence *) malloc(sizeof(sentence));

    if (sent1 == NULL)
        return;

    sent1->str = "You're beat! and yet, you must allow,\n"
        "I bore my house upon my back!\n";
    sent1->next = head;
    head = sent1;

    printf("%s", head->str);
}

