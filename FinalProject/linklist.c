#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

void addCard(card *pointer, card **head, card **tail, card newCard)
{
    card *temp = (card *)malloc(sizeof(card));

    scanf("%s%d%s%*c", temp->colour, &temp->value, temp->action);

    if (*head == NULL)
    {
        temp->previous = NULL;
        temp->next = NULL;
        *head = temp;
        *tail = temp;
    }
    else if (pointer->next == NULL)
    {
        temp->previous = pointer;
        temp->next = NULL;
        pointer->next = temp;
        *tail = temp;
    }
    else
    {
        temp->pointer = pointer->next;
        temp->previous = pointer;
        pointer->next = temp;
        temp->next->previous = temp;
    }
}

void removeCard(card *pointer, card **head, card **tail, card cardChoice)
{
    if (pointer == *head)
    {
        *head = pointer->next;
    }
    else
    {
        pointer->previous->next = pointer->next;
    }

    if (pointer == *tail)
    {
        *tail = pointer->previous;
    }
    else
    {
        pointer->next->previous = pointer->previous;
    }

    free(pointer);
}

void shuffleDeck(card deck[])
{
    int i, j, k;
    card temp;
    for (i = 0; i < 108; i++)
    {
        j = rand() % 108;
        k = rand() % 108;
        temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}

void printCard(card *pointer, int handSize)
{
    int i, comma[handSize - 1];
    card temp;

    for (i = 0; i < handSize - 1; i++)
    {
        comma[i] = ',';
    }
    for (i = 0; i < handSize; i++)
    {
    }
}

void newDeck(FILE *inputFile, card deck[])
{
    int i;

    for (i = 0; i < 108; i++)
    {
        fscanf(inputFile, "%s%d%s%*c", deck[i].colour, &deck[i].value, deck[i].action);
    }
}
