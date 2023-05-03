typedef struct card_s
{
    char colour[7];
    int value;
    char action[15];
    struct card_s *previous, *next, *pointer;
} card;

void addCard(card *pointer, card **head);
void removeCard(card *pointer, card **head, int cardChoice);
void printCard(card *pointer, int handSize);
void newDeck(FILE *input, card deck[]);
void shuffleDeck(card deck[]);