#include <stdio.h>

void LetterCounter(FILE *input, char userInput, int *uppercaseCount, int *lowercaseCount)
{
    int count = 0;
    char letter;
    input = fopen("Hamlet.txt", "r");

    while (!feof(input))
    {
        fscanf(input, " %c", &letter);
        if (userInput == letter)
        {
            count++;
        }
    }
    fclose(input);
}

int main()
{
    FILE *input;
    char userInput;

    printf("Which letter would you like to find?");
    scanf(" %c\n", &userInput);
}