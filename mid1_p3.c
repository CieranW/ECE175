#include <stdio.h>

int main()
{
    int userNum;

    scanf("%d", &userNum);
    if (userNum != 1)
    {
        while (userNum != 1)
        {
            printf("%d\t", userNum);
            if (userNum % 2 == 0)
            {
                userNum /= 2;
            }
            else if (userNum % 2 == 1)
            {
                userNum = (userNum * 3) + 1;
            }
        }
    }
    if (userNum == 1)
    {
        printf("%d\n", userNum);
    }
    return 0;
}