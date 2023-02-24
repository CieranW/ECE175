#include <stdio.h>

int SumInts(int target)
{
    FILE *inp;
    inp = fopen("MyDataF.dat", "r");
    int finalSum = 0, n;

    while (!feof(inp))
    {
        fscanf(inp, "%d", &n);
        if (n >= target)
        {
            finalSum += n;
        }
    }

    fclose(inp);
    return finalSum;
}

int main()
{
    // Problem 1
    int targetValue;

    printf("Find the sum of all values above what threshold?\n");
    scanf("%d", &targetValue);

    printf("The sum of all values >= %d was found to be %d\n", targetValue, SumInts(targetValue));

    return 0;
}