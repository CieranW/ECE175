#include <stdio.h>

int SumInts(FILE *inp, int target)
{
    inp = fopen("MyDataF.dat", "r");
    int finalSum, n;

    while (!feof(inp))
    {
        fscanf(inp, "%d", &n);
        if (n >= target)
        {
            finalSum += n;
        }
    }
}