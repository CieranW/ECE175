/* Sudoku is a number-placement puzzle played on a 9-by-9 grid. The objective is to fill the grid with digits so that each column, each row, and each of the nine 3-by-3 subgrids that compose the grid contain all of the digits from 1 to 9. For complete Sudoku rules, check [Wikipedia]{http://en.wikipedia.org/wiki/Sudoku}.

Write a program that reads a sudoku file as input and checks if the file is a proper solution to the Sudoku puzzle. Your program should use a function called checkBoard which returns true if the board is a valid sudoku board and zero otherwise.

void readSudoku(int x[][9], FILE *inp); // reads a sudoku board from a file pointed by inp
void printSudoku(int x[][9]); // prints a sudoku board in the format shown below
bool checkSudoku(int x[][9]); // checks if this is a valid sudoku board and returns true or false */

#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

void readSudoku(int x[][SIZE], FILE *inp);
void printSudoku(int x[][SIZE]);
bool checkSudoku(int x[][SIZE]);

int main(void)
{

    int sudoku[SIZE][SIZE]; // sudoku is a two dimensional array that holds all the values of the board
    FILE *inp;

    inp = fopen("sudoku1.txt", "r");

    if (inp == NULL)
    {
        return -1;
    }
    else
    {
        // your code goes here
    }
}

void readSudoku(int x[][SIZE], FILE *inp)
{ // reads a sudoku file into array x
}

void printSudoku(int x[][SIZE])
{ // prints a soduko board
}

bool checkSudoku(int x[][SIZE])
{ // returns true if x is a valid sudoku boards and false otherwise
}
