#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "linklist.h"

typedef struct card_s
{
    char colour[7];
    int value;
    char action[15];
    struct card_s *previous, *next, *pointer;
} card;

card *newDeck(FILE *input);
void deck1(FILE *input, card *deck);
void initHand(card *deck, card **player1, card **player2);
void addCard(card *deck, card **head, int cardPosition);
void removeCard(card *pointer, card **head, int cardChoice);
void printCard(card *pointer, int handSize);
void shuffleDeck(card deck[]);
void countPoints(int *points, card *playerHand, int handSize);

int main(void)
{
    // card *deck = NULL;
    card *player1, *player2, deck[108], discardPile[108], centerPile[5];
    int i, j, k, turn, handSize1 = 7, handSize2 = 7, player1Choice, player2Choice, centerPileSize, p1Point, p2Point;
    FILE *inputFile = fopen("cardsData.txt", "r");

    // deck = newDeck(inputFile);
    deck1(inputFile, deck);
    shuffleDeck(deck);
    for (i = 0; i < 108; i++)
    {
        printf("%s %d %s\n", deck[i].colour, deck[i].value, deck[i].action);
    }

    initHand(deck, &player1, &player2);

    turn = 1;

    // For center pile, take the first two cards from the main deck to be the center pile. Increment the center pile accordingly each time a card is removed, added, etc.
    printf("Center cards: ");
    for (i = 0; i < centerPileSize; i++)
    {
        printf("%s %d %s", centerPile[i].action, centerPile[i].value, centerPile[i].action);
    }
    if (turn == 1)
    {
        printf("Player 1's hand: ");
        printCard(player1, handSize1);
        printf("Which card would you like to play? (1-%d)\n", handSize1);
        // scanf("%d", &player1Choice);
        //  removeCard(deck, &player1, player1Choice);
        //   Match? Then draw two new cards from the deck. Match bonuses??
        //   Then draw a card from the deck for player hand
        //   Track the number of cards in each hand, if left with two
    }
    else if (turn == 2)
    {
        printf("Player 2's hand: ");
        printCard(player2, handSize2);
    }
}

void deck1(FILE *input, card *deck)
{
    int i;
    for (i = 0; i < 108; i++)
    {
        fscanf(input, "%s%d%s", deck[i].colour, &deck[i].value, deck[i].action);
    }
}

card *newDeck(FILE *inputFile) // Make the deck a linked list
{
    int i = 0;
    card *head = NULL;
    card *temp = NULL;
    card *pointer = NULL;

    for (i = 0; i < 108; i++)
    {
        temp = (card *)malloc(sizeof(card));
        fscanf(inputFile, "%s%d%s", temp->colour, &(temp->value), temp->action);
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            pointer = head;
            while (pointer->next != NULL)
            {
                pointer = pointer->next;
            }
            pointer->next = temp;
        }
    }
    return head;
}

void initHand(card *deck, card **player1, card **player2) // Remove card from the deck, add to the player hand. Call in the entire deck, go through a for loop with odd to 1, even to 2.
{
    int i = 0;
    *player1 = (card *)malloc(sizeof(card));
    *player2 = (card *)malloc(sizeof(card));
    card *temp1 = *player1;
    card *temp2 = *player2;

    strcpy(temp1->colour, deck[i].colour);
    strcpy(temp1->action, deck[i].action);
    temp1->value = deck[i].value;

    i++;

    strcpy(temp2->colour, deck[i].colour);
    strcpy(temp2->action, deck[i].action);
    temp2->value = deck[i].value;

    for (i = 2; i < 14; i++)
    {
        if (i % 2 != 0)
        {
            temp1->next = (card *)malloc(sizeof(card));
            temp1 = temp1->next;
            strcpy(temp1->colour, deck[i].colour);
            strcpy(temp1->action, deck[i].action);
            temp1->value = deck[i].value;
            temp1->next = 0;
        }
        else if (i % 2 == 0)
        {
            temp2->next = (card *)malloc(sizeof(card));
            temp2 = temp2->next;
            strcpy(temp2->colour, deck[i].colour);
            strcpy(temp2->action, deck[i].action);
            temp2->value = deck[i].value;
            temp2->next = 0;
        }
    }
}

void addCard(card *deck, card **head, int cardPosition)
{
    card *add = (card *)malloc(sizeof(card));
    strcpy(add->colour, deck[cardPosition].colour);
    strcpy(add->action, deck[cardPosition].action);
    add->value = deck[cardPosition].value;
    add->pointer = *head;

    *head = add;
}

void removeCard(card *pointer, card **head, int cardChoice) // make cardChoice instead of the location, the actual card value. so will be of type card instead of int.
{
    card *delCard = head[cardChoice - 1];
    card *temp = (card *)malloc(sizeof(card));

    strcpy(temp->colour, head[cardChoice]->colour);
    strcpy(temp->action, head[cardChoice]->action);
    temp->value = head[cardChoice]->value;

    // // if head or del is null, deletion is not possible
    // if (*head == NULL || delCard == NULL)
    //     return;

    // // if del_node is the head node, point the head pointer to the next of del_node
    // if (*head == delCard)
    //     *head = delCard->next;

    // // if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
    // if (delCard->next != NULL)
    //     delCard->next->prev = delCard->prev;

    // // if del_node is not the first node, point the next of the previous node to the next node of del_node
    // if (delCard->prev != NULL)
    //     delCard->prev->next = delCard->next;

    // free the memory of del_node
    free(head);
}

// void playerSubtractCard(card **head, card *deck, int listIndex, int *discardIndex)
// {
//     // Removes a card from the player's hand
//     card *tail = *head;
//     card *removed;
//     if (listIndex == 0)
//     {
//         removed = *head;
//         *head = (*head)->pt;
//         (*discardIndex)++;
//         deck[*discardIndex].value = removed->value;
//         strcpy(deck[*discardIndex].color, removed->color);
//         strcpy(deck[*discardIndex].action, removed->action);
//         free(removed);
//         return;
//     } // This above function removes the head card from the players linked list if that is the card they desire to play.
//     while (listIndex != 1)
//     {
//         // If the removed card is elsewhere
//         tail = tail->pt;
//         listIndex--;
//     } // This finds out which node the player wants to remove
//     // Make the previous node point to the next node and free the removed card and add it to the discard pile
//     removed = tail->pt;
//     tail->pt = tail->pt->pt;
//     (*discardIndex)++;
//     deck[*discardIndex].value = removed->value;
//     strcpy(deck[*discardIndex].color, removed->color);
//     strcpy(deck[*discardIndex].action, removed->action);
//     free(removed);
// }

void shuffleDeck(card deck[])
{
    int i, j, k;
    card temp;
    for (i = 0; i < 100000; i++)
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

void countPoints(int *points, card *playerHand, int handSize)
{
    int i;

    for (i = 0; i < handSize; i++)
    {
        if (playerHand[i].colour == 'black' && playerHand[i].value == 2 && playerHand[i].action == 'none')
        {
            *points += 20;
        }
        else if (playerHand[i].value == 11 && playerHand[i].action == 'AnyNumber')
        {
            *points += 40;
        }
        else
        {
            *points += playerHand[i].value;
        }
    }
}

int count_cards(card *hand)
{
    int count = 0;
    while (hand != NULL)
    {
        count++;
        hand = hand->next;
    }

    return count;
}
