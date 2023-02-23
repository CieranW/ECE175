#include <stdio.h>

int main()
{
    int max, min, userNum;

    while (userNum > 0) // O(n^2)
    {
        scanf("%d", &userNum);
        if (userNum > max)
        {
            max = userNum;
        }
        else if (userNum < min)
        {
            min = userNum;
        }
    }
    printf("%d", max);
    return 0;
}