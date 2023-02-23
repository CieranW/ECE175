#include <stdio.h>

int main()
{
    int high, low, x;

    scanf("%d %d %d", &low, &high, &x);

    for (int i = low; i <= high; i++)
    {
        if (i % x == 2)
        {
            printf("%d", i);
        }
    }
    return 0;
}