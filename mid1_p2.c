#include <stdio.h>

int main()
{
    int max = 0, min = -1, userNum;

    while (userNum > -1) // O(n^2)
    {
        scanf("%d", &userNum);
        if (userNum >= max)
        {
            max = userNum;
        }
        else if (userNum <= min)
        {
            min = userNum;
        }
    }
    printf("%d", max);
    return 0;
}