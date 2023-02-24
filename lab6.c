#include <stdio.h>

int SumInts(int target)
{
    FILE *inp;
    inp = fopen("MyDataF.dat", "r");
    int finalSum = 0, n;

    while (!feof(inp)) // O(n^2)
    {
        fscanf(inp, "%d", &n);
        if (n >= target)
        {
            finalSum += n;
        }
    }

    fclose(inp);
    return finalSum;
}

void Credit(int quarter, int dime, int nickel, int penny, int *dollars, int *cents)
{ // O(1)
    int totalCash = 0;
    totalCash = quarter * 25 + dime * 10 + nickel * 5 + penny;
    *dollars = totalCash / 100;
    *cents = totalCash % 100;
}
int main()
{
    // Problem 1
    int targetValue;

    printf("Find the sum of all values above what threshold?\n");
    scanf("%d", &targetValue);

    printf("The sum of all values >= %d was found to be %d\n", targetValue, SumInts(targetValue));

    // Problem 2
    int quarter, dime, nickel, penny, dollars, cents;

    printf("Enter coins info (Quarter, Dime, Nickel, Penny): \n");
    scanf("%d %d %d %d", &quarter, &dime, &nickel, &penny);

    Credit(quarter, dime, nickel, penny, &dollars, &cents);

    printf("Coin Credit:\nDollars: %d\nChange: %d cents\n", dollars, cents);
    return 0;
}