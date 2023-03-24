#include <stdio.h>
#include <stdbool.h>
void ReadArray(FILE *inp, int x[][6]);

void ReadArray(FILE *inp, int x[][6])
{
    int i, j, row = 0, col = 0, diag = 0;
    bool magic = false;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            fscanf(inp, "%d", &x[i][j]);
        }
    }

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (x[i][j] == x[j][i])
            {
                magic = true;
            }
        }
    }

    if (magic == true)
    {
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                printf("%d\t", x[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < 6; i++)
        {
            col += x[i][0];
        }
        for (i = 0; i < 6; i++)
        {
            row += x[0][i];
        }
        j = 0;
        for (i = 0; i < 6; i++)
        {
            diag += x[i][j++];
        }
        printf("Sum of numbers in a row: %d\nSum of numbers in a column: %d\nSum of numbers in a diagonal: %d\n", row, col, diag);
    }
}

int main()
{
    FILE *inp;
    inp = fopen("array.txt", "r");
    int x[6][6];
    ReadArray(inp, x);
    return 0;
}