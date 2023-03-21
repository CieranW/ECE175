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

bool letterCheck(char x[], char y[], int len, char c, int *times);

int main()
{

    /* Type your code here. */

    return 0;
}

bool letterCheck(char x[], char y[], int len, char c, int *times)
{
    // checks if letter c exists in x[]. Discovered letters are stored in y[].
    // times holds how many
    // times c appeared in x.
}