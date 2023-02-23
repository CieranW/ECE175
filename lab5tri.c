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
            triNum = x;
        }
    }

    return triNum;
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
        printf("%d", triNumber);
    }
    fclose(triNum);

    return 0;
}