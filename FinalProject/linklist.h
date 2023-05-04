typedef struct card_s
{
    char colour[7];
    int value;
    char action[15];
    struct card_s *next, *prev;
} card;

void initHand(card *pointer);
void addCard();
void removeCard(card *pointer, card **head, int cardChoice);
void printCard(card *pointer, int handSize);
void newDeck(FILE *input, card deck[]);
void shuffleDeck(card deck[]);
void countPoints(int *pointer, card *playerHand, int handSize);