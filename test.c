#include <stdio.h>
#include <stdbool.h>
#include <math.h>

char Decrypt(char letter)
{
    char userLetter;

    scanf("%c", &userLetter);

    while (userLetter != letter)
    {
        i++;
    }

    return 'a' + i;
}
