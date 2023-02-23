#include <stdio.h>

int main()
{
    int high, low, x, counter = 0;

    scanf("%d %d %d", &low, &high, &x);

    for (int i = low; i <= high; i++)
    {
        if (i % x == 0)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}