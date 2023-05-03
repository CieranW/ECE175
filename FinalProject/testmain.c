#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

// typedef struct card_s
// {
//     char colour[7];
//     int value;
//     char action[15];
//     struct card_s *previous, *next;
// } card;

void addCard(card *pointer, card **head);
void removeCard(card *pointer, card **head, int cardChoice);
void printCard(card *pointer, int handSize);
void newDeck(FILE *input, card deck[]);
void shuffleDeck(card deck[]);

void addCard(card *pointer, card **head)
{
    card *temp = (card *)malloc(sizeof(card));

    strcpy(temp->colour, pointer->colour);
    strcpy(temp->action, pointer->action);
    temp->value = pointer->value;
    temp->pointer = *head;
    *head = temp;
}

void removeCard(card *pointer, card **head, int cardChoice)
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
    int i;
    char comma[handSize - 1];
    card temp;

    for (i = 0; i < handSize - 1; i++)
    {
        comma[i] = ',';
    }
    for (i = 0; i < handSize; i++)
    {
        printf("%s %d %s%c ", pointer->colour, pointer->value, pointer->action, comma[i]);
    }
    printf("\n");
}

void newDeck(FILE *inputFile, card deck[])
{
    int i;

    for (i = 0; i < 108; i++)
    {
        fscanf(inputFile, "%s%d%s%*c", deck[i].colour, &deck[i].value, deck[i].action);
    }
}

int main(void)
{
    card *player1, *player2, deck[108], discardPile[108], centerPile[5];
    int i, j, k, turn, handSize1 = 7, handSize2 = 7, player1Choice, player2Choice;
    FILE *inputFile = fopen("cardsData.txt", "r");

    newDeck(inputFile, deck);
    shuffleDeck(deck);

    for (i = 0; i < 14; i++)
    {
        addCard(&deck[i], &player1);
        addCard(&deck[++i], &player2);
    }

    turn = 0;

    if (turn == 1)
    {
        printf("Player 1's hand: ");
        printCard(player1, handSize1);
        printf("Which card would you like to play? (1-%d)\n", handSize1);
        scanf("%d", &player1Choice);
        removeCard(deck, &player1, player1Choice);
    }
    else if (turn == 2)
    {
        printf("Player 2's hand: ");
        printCard(player2, handSize2);
    }
}
