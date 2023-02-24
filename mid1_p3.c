#include <stdio.h>

int main()
{
    int userNum;

    scanf("%d", &userNum);

    while (userNum != 1)
    {
        if (userNum % 2 == 0)
        {
            userNum /= 2;
        }
        else if (userNum % 2 == 1)
        {
            userNum = (userNum * 3) + 1;
        }
        printf("%d\t", userNum);
    }
    return 0;
}