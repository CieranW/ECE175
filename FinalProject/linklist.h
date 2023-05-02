typedef struct card_s
{
    char colour[7];
    int value;
    char action[15];
    struct card_s *pointer;
} card;

void addCard(card *pointer, card **head, card **tail);
void removeCard(card *pointer, card **head, card **tail);
void printCard();
void newDeck(FILE *input, card deck[]);
void discardDeck();
void shuffleDeck(card deck[]);