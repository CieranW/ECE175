#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

int main(void)
{
    card player1[20], player2[20], deck[108], discardPile[108], centerPile[5];
    int i;
    FILE *inputFile = fopen("cardsData.txt", "r");

    newDeck(inputFile, deck);
    shuffleDeck(deck);

    for (i = 0; i < 7; i++)
    {
        player1[i] = deck[rand() % 108];
        player2[i] = deck[rand() % 108];
    }

    for (i = 0; i < 7; i++)
    {
        printf("%s %d %s\n", player1[i].colour, player1[i].value, player1[i].action);
        printf("%s %d %s\n", player2[i].colour, player2[i].value, player2[i].action);
    }
}
