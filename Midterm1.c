#include <stdio.h>

int main()
{
    char userInput, upperLetter, lowerLetter, letter = '1';
    int uppercaseCount, lowercaseCount;
    FILE *input;
    input = fopen("Hamlet.txt", "r");

    lowercaseCount = 0;
    uppercaseCount = 0;

    printf("Which letter would you like to find?");
    scanf(" %c\n", &userInput);

    if (userInput >= 'a' && userInput <= 'z')
    {
        upperLetter = userInput - 'a' + 'A';
    }
    if (userInput >= 'A' && userInput <= 'Z')
    {
        lowerLetter = userInput - 'A' + 'a';
    }

    while (!feof(input))
    {
        int i = 1;
        while (letter != '\n')
        {
            fscanf(input, " %c", &letter);
            if (letter == lowerLetter)
            {
                lowercaseCount++;
            }
            else if (letter == upperLetter)
            {
                uppercaseCount++;
            }
            printf("Line %d: '%c' was found %d times, '%c' was found %d times.\n", i, upperLetter, uppercaseCount, lowerLetter, lowercaseCount);
        }
        if (letter == '\n')
        {
            i++;
        }
    }

    fclose(input);

    return 0;
}