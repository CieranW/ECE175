#include <stdio.h>

int main(void)
{

    // Problem 1
    int n, i, counter = 1;

    printf("Enter a value of n: \n");
    scanf("%d", &n);

    for (i = 1; i <= n; i = counter * 14)
    {
        counter += 1;
        printf("%d ", i);
    }

    printf("\nTotal numbers found: %d\n", counter - 1);

    // Problem 2
    int n = 0, i, j;
    char userInitial;

    while (n < 1 || n > 9)
    {
        printf("Enter an integer between 1 and 9: \n");
        scanf("%d", &n);
    }

    printf("Enter your first initial: \n");
    scanf(" %c", &userInitial);

    for (i = 0; i <= n; i++) // Tracks the rows
    {
        for (j = 1 + i; j <= n; j++)
        {
            printf(" "); // Prints the number of spaces
        }
        for (j = 0; j < (2 * i - 1); j++) // Outputs the character
        {
            printf("%c", userInitial);
        }
        printf("\n");
    }

    return 0;
}