#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int rollDice(void);

int rollDice(void)
{
    int die1, die2;
    // This function is to roll dice, calculate and return sum  // and display
    // 1) write a statement using rand() to generate a face of  // one die between 1 and 6, assign it to die1
    die1 = (rand() % 6) + 1;
    // 2) write a statement using rand() to generate a face of  // one die between 1 and 6, assign it to die2
    die2 = (rand() % 6) + 1;
    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}

int main()
{
    int turnCount = 0, point = 0;
    bool terminate = false, win = false;
    int diceSum;
    srand((int)time(NULL));

    while (1)
    {
        diceSum = rollDice();
        if (turnCount == 0 && (diceSum == 7 || diceSum == 11))
        {
            win = true;
            break;
        }
        else if (turnCount == 0 && (diceSum == 2 || diceSum == 3 || diceSum == 12))
        {
            win = false;
            break;
        }
        else if (turnCount == 0 && (diceSum == 4 || diceSum == 5 || diceSum == 6 || diceSum == 8 || diceSum == 9 || diceSum == 10))
        {
            point = diceSum;
            printf("Point is %d\n", point);
        }
        else if (turnCount != 0 && diceSum == point)
        {
            win = true;
            break;
        }
        else if (turnCount != 0 && diceSum == 7)
        {
            win = false;
            break;
        }

        printf("Press the Enter key to continue\n");
        scanf("%*c");
        turnCount++;
    }

    if (win == true)
    {
        printf("Player wins\n");
    }
    else
    {
        printf("Player loses\n");
    }

    return 0;
}