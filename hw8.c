/* Sudoku is a number-placement puzzle played on a 9-by-9 grid. The objective is to fill the grid with digits so that each column, each row, and each of the nine 3-by-3 subgrids that compose the grid contain all of the digits from 1 to 9. For complete Sudoku rules, check [Wikipedia]{http://en.wikipedia.org/wiki/Sudoku}.

Write a program that reads a sudoku file as input and checks if the file is a proper solution to the Sudoku puzzle. Your program should use a function called checkBoard which returns true if the board is a valid sudoku board and zero otherwise.*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

void readSudoku(int x[][SIZE], FILE *inp); // reads a sudoku board from a file pointed by inp
void printSudoku(int x[][SIZE]);           // prints a sudoku board in the format shown below
bool checkSudoku(int x[][SIZE]);           // checks if this is a valid sudoku board and returns true or false

int main(void)
{

    int sudoku[SIZE][SIZE]; // sudoku is a two dimensional array that holds all the values of the board
    bool check = false;
    FILE *inp;

    inp = fopen("sudoku1.txt", "r");

    if (inp == NULL)
    {
        return -1;
    }
    else
    {
        // your code goes here
        readSudoku(sudoku, inp);
        check = checkSudoku(sudoku);

        if (check == true)
        {
            printSudoku(sudoku);
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

void readSudoku(int x[][SIZE], FILE *inp)
{ // reads a sudoku file into array x
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fscanf(inp, "%d", &x[i][j]);
        }
    }
}

void printSudoku(int x[][SIZE])
{ // prints a soduko board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", x[i][j]);
            if (j == 2 || j == 5)
            {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5)
        {
            for (int k = 0; k < 21; k++)
            {
                printf("-");
            }
            printf("\n");
        }
    }
}

bool checkSudoku(int x[][SIZE])
{ // returns true if x is a valid sudoku boards and false otherwise
    int i, j, k, row[SIZE], col[SIZE], square[3][3];

    // Assigns row and column variables from array x.
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            row[i] = x[i][j];
            col[i] = x[j][i];
        }
    }
    // Assigns square a section of the sudoku puzzle.
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            square[i][j] = x[i][j];
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ()
        }
    }
}
