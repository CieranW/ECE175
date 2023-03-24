#include <stdio.h>
void ReadArray(FILE *inp, int x[5][5]);

void ReadArray(FILE *inp, int x[5][5])
{
    int hor[5], vert[5], temp[5], i, j;

    // Scans input from file into array
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            fscanf(inp, "%d", &x[i][j]);
        }
    }

    // Initialize both ver and hor to 0 for each index
    for (i = 0; i < 5; i++)
    {
        hor[i] = 0;
        vert[i] = 0;
    }

    // Counts number of times 1 appears in each row and assigns a value of 1 or 0 if number of times is odd or even respectively. Outputs each number into an array hor[5]
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            hor[i] += x[i][j];
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (hor[i] % 2 == 0)
        {
            hor[i] = 0;
        }
        else
        {
            hor[i] = 1;
        }
    }

    // Similar to the above for loops except for vert
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            vert[i] += x[j][i];
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (vert[i] % 2 == 0)
        {
            vert[i] = 0;
        }
        else
        {
            vert[i] = 1;
        }
    }

    // Prints out the horizontal and vertical parity
    printf("Horizontal partiy: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d", hor[i]);
    }
    printf("\nVertical partiy: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d", vert[i]);
    }
    printf("\n");
}

int main()
{
    FILE *inp;
    inp = fopen("array2.txt", "r");
    int x[5][5];

    ReadArray(inp, x);

    return 0;
}