#include <stdio.h>
#include <math.h>

void Init(int x[], int size)
{
    for (int i = 0; i < size; i++)
    {
        x[i] = 1;
    }
}

void PrintPrime(int x[], int size)
{
    int i, j;
    for (i = 3; i < size; i++)
    {
        if (i % 2 == 0)
        {
            x[i] = 0;
        }
        for (j = 3; j < i - 1; j += 2)
        {
            if (i % j == 0)
            {
                x[i] = 0;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        if (x[i] == 1)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int size;
    int x[1000];

    scanf("%d", &size);
    Init(x, size);
    PrintPrime(x, size);

    return 0;
}