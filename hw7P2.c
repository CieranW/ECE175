/* Write an interactive program that plays a game of hangman. Store the characters of the word to be guessed in an array of type char (you can initialize your character array at declaration). Words are seven letters long. Initially, the program displays the length of the word to be guessed. This is in the form of successive stars (see example). The player guesses letters belonging to the secret word one by one. After each guess, the letters that have been guessed and the number of wrong guesses are displayed on the screen. Your program should terminate when either the entire word is guessed or 4 incorrect guesses have been attempted.

Your code shall use the following function:

bool letterCheck(char secret[], char found[], int len, char c, int *times);

The function receives as input array secret that holds the secret word, array found that holds the letters that have been found thus far, the length of the secret word, and the input character from the user. The function returns if the letter given by the user was found in array secret (via the boolean return variable), updates array found, and also returns the number of times the letter was found via pointer times

Test your program for the words: abandon, annoyed, finance, aerobic, inferno, infancy.

Sample output
Hi, let’s play hangman. The secret word is:
*******
Guess a letter:t
Letter t is not part of the secret word, You have 3 attempts left.
*******
Guess a letter:a
Letter a exists 2 times in the secret word, You have 3 attempts left.
a*a****
Guess a letter:e
Letter e is not part of the secret word, you have 2 attempts left. … */

#include <stdio.h>
#include <stdbool.h>

bool letterCheck(char word[], char guess[], int lengthOfWord, char userGuess, int *times);

int compareArray(char a[], char b[], int size);

bool letterCheck(char a[], char guess[], int lengthOfWord, char userGuess, int *times)
{
    // checks if letter userGuess exists in word[]. Discovered letters are stored in guess[].
    // times holds how many times userGuess appeared in word.
    int i;
    *times = 0;
    for (i = 0; i < lengthOfWord; i++)
    {
        if (a[i] == userGuess)
        {
            guess[i] = userGuess;
            *times += 1;
        }
    }
    if (*times != 0)
    {
        //*times;
        return true;
    }
    else
    {
        return false;
    }
}

int compareArray(char a[], char b[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int lengthOfWord = 7, times, i, count = 4, compare = 1;
    bool attempt;
    char userGuess, guess[lengthOfWord];

    char a[7] = {'a', 'b', 'a', 'n', 'd', 'o', 'n'}; // abandon
    // char b[7] = {'i', 'n', 'f', 'e', 'r', 'n', 'o'}; // inferno
    // char c[7] = {'a', 'n', 'n', 'o', 'y', 'e', 'd'}; // annoyed
    // char d[7] = {'f', 'i', 'n', 'a', 'n', 'c', 'e'}; // finance
    // char e[7] = {'a', 'e', 'r', 'o', 'b', 'i', 'c'}; // aerobic
    // char f[7] = {'i', 'n', 'f', 'a', 'n', 'c', 'y'}; // infancy

    for (i = 0; i < lengthOfWord; i++)
    {
        guess[i] = '*';
    }

    printf("Let's play hangman\n");
    for (i = 0; i < lengthOfWord; i++)
    {
        printf("%c", guess[i]);
    }
    printf("\n");

    while (count > 0 && compare == 1)
    {
        printf("Guess a letter: ");
        scanf(" %c", &userGuess);
        attempt = letterCheck(a, guess, lengthOfWord, userGuess, &times);
        if (attempt == true)
        {
            printf("Letter %c exists %d times in the secret word. You have %d attemps left.\n", userGuess, times, count);
            for (i = 0; i < lengthOfWord; i++)
            {
                printf("%c", guess[i]);
            }
            printf("\n");
        }
        else
        {
            count -= 1;
            printf("Letter %c is not part of the word. You have %d guesses remaining.\n", userGuess, count);
        }
        compare = compareArray(a, guess, lengthOfWord);
    }

    if (count == 0)
    {
        printf("You have no attempts remaining. The secret word was:\n");
        for (i = 0; i < lengthOfWord; i++)
        {
            printf("%c", a[i]);
        }
        printf("\n");
    }
    else if (compare == 0)
    {
        printf("Congratulations, you guessed the word correctly. You had %d attempts remaining.\n", count);
    }

    return 0;
}
