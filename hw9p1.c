#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char s[]); // function that reverses a string

int main()
{
    /* Type your code here. */
    char userInput[100];
    bool newLine = false;

    printf("Enter a sentence:\n");

    while (newLine == false && userInput[0] != '\n')
    {
        scanf("%s", userInput);
        reverse(userInput);
        if (userInput[0] == '\n')
        {
            newLine = true;
        }
    }

    return 0;
}

void reverse(char s[])
{
    /* Function that reverses a string here */
    int len, i, j;
    char temp;

    len = strlen(s);

    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
    printf(" ");
}