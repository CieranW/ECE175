typedef struct card_s
{
    char colour[7];
    int value;
    char action[15];
    struct card_s *pointer;
} card;

void addCard(card *newCard);
void removeCard(card *hand);