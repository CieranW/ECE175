#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int Triangular(int x)
{
    int testNum, triNum;

    testNum = 2 * x;
    for (int i = 0; i <= testNum; i++)
    {
        long int j = (pow(i, 2) + i);
        if (testNum == j)
        {
            return x;
        }
    }
    return -1;
}

int CountInts(int target)
{
    // Problem 2
    FILE *friDat;
    int numScan, count = 0;

    friDat = fopen("Fridays_Data.dat", "r");

    if (NULL == friDat)
    {
        printf("Friday_Data.dat can't be opened.");
        return -1;
    }

    while (!feof(friDat))
    {
        fscanf(friDat, "%d", &numScan);
        if (numScan >= target)
        {
            count += 1;
        }

        if (target < 0)
        {
            count -= 1;
        }
        count = count;
    }
    fclose(friDat);
    return count;
}

int main()
{
    // Problem 1
    FILE *triNum;
    triNum = fopen("numbers.txt", "r");
    int numInp;

    if (NULL == triNum)
    {
        printf("numbers.txt not found");
        return -1;
    }
    while (!feof(triNum))
    {
        fscanf(triNum, "%d", &numInp);
        int triNumber = Triangular(numInp);
        if (triNumber != -1)
            printf("%d\n", triNumber);
    }
    fclose(triNum);

    // Problem 2
    int target, counter;

    printf("Count the number of integers above what threshold?\n");
    scanf("%d", &target);

    counter = CountInts(target);
    printf("The number of integers >= %d was found to be %d\n", target, counter);

    return 0;
}