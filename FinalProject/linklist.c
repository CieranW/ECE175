#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

void addCard(card *new)
{
    card *temp = (card *)malloc(sizeof(card));

    if (*head == NULL)
    {
        temp->previous = NULL;
        temp->next = NULL;
        *head = temp;
        *tail = temp;
    }

    if (*pointer == *head)
    {
        *head = pointer;
    }
    else
    {
        (pointer->previous)->next = pointer->next;
    }
    if (*tail == *previous)
    {
        *tail = previous;
    }
    else
    {
        (pointer->next)->previous = pointer->previous;
    }
}

void removeCard(card *hand)
{
}