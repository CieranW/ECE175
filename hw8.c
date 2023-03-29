/* Sudoku is a number-placement puzzle played on a 9-by-9 grid. The objective is to fill the grid with digits so that each column, each row, and each of the nine 3-by-3 subgrids that compose the grid contain all of the digits from 1 to 9. For complete Sudoku rules, check [Wikipedia]{http://en.wikipedia.org/wiki/Sudoku}.

Write a program that reads a sudoku file as input and checks if the file is a proper solution to the Sudoku puzzle. Your program should use a function called checkBoard which returns true if the board is a valid sudoku board and zero otherwise.*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

void readSudoku(int x[][SIZE], FILE *inp);                            // reads a sudoku board from a file pointed by inp
void printSudoku(int x[][SIZE]);                                      // prints a sudoku board in the format shown below
bool checkSudoku(int x[][SIZE]);                                      // checks if this is a valid sudoku board and returns true or false
void checkArray(int sudoku[SIZE][SIZE], int i, int j, int square[8]); // checks each square into a temp array to run through a check to see if it matches the necessary conditions

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
            printf("This is a valid sudoku puzzle\n");
            // printSudoku(sudoku);
            return 0;
        }
        else
        {
            printf("This is not a valid sudoku puzzle\n");
            return 0;
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
{
    // returns true if x is a valid sudoku boards and false otherwise
    int i, j, k, row[SIZE], col[SIZE], square[SIZE], temprow[SIZE], tempcol[SIZE], tempbox[9], counterRow, counterCol, counterBox, sudoku[SIZE][SIZE];
    bool check1 = false, check2 = false;

    // Initializes the three comparison arrays to 0
    for (i = 0; i < SIZE; i++)
    {
        row[i] = 0;
        col[i] = 0;
        square[i] = 0;
        temprow[i] = 0;
        tempcol[i] = 0;
        tempbox[i] = 0;
        for (j = 0; j < SIZE; j++)
        {
            sudoku[i][j] = x[i][j];
        }
    }
    while (check1 == false || check2 == false)
    {
        // Assigns row and column variables from array x.
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                row[j] = x[i][j];
                col[j] = x[j][i];
            }
            for (i = 0; i < 9; i++)
            {
                temprow[row[i] - 1] = 1;
                tempcol[col[i] - 1] = 1;
            }
            counterRow = 0, counterCol = 0;
            for (k = 0; k < 9; k++)
            {
                counterRow += temprow[k];
                counterCol += tempcol[k];
            }
            if (counterRow == 9 && counterCol == 9)
            {
                check1 = true;
            }
        }
        // Assigns square a section of the sudoku puzzle.
        for (int i = 0; i < 9; i += 3)
        {
            for (j = 0; j < 9; j += 3)
            {
                checkArray(sudoku, i, j, square);
            }
            for (i = 0; i < 9; i++)
            {
                tempbox[square[i] - 1] = 1;
            }
            counterBox = 0;
            for (i = 0; i < 9; i++)
            {
                counterBox += tempbox[i];
            }
            if (counterBox == 9)
            {
                check2 = true;
            }
        }

        if (check1 == true && check2 == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void checkArray(int sudoku[SIZE][SIZE], int i, int j, int square[8])
{
    int l, m, k = 0;

    for (l = i; l < i + 3; ++l)
    {
        for (m = j; m < j + 3; ++m)
        {
            square[k++] = sudoku[l][m];
        }
    }
}
