#include <stdio.h>
#include <stdbool.h>

int DaysInFeb(int userYear)
{ // O(log(n))
    if (userYear % 4 != 0)
    {
        return 28;
    }
    else if (userYear % 100 != 0)
    {
        return 29;
    }
    else if (userYear % 400 != 0)
    {
        return 28;
    }

    else
    {
        return 29;
    }
}

int main()
{
    int userYear;

    scanf("%d", &userYear);
    printf("%d has %d days in February.\n", userYear, DaysInFeb(userYear));
}