#include <stdio.h>

int main(void)
{
    double loan, payment, interest, balance;
    int counter = 0;
    scanf("%lf %lf %lf", &loan, &payment, &interest);

    while (balance > 0) // Change into a for loop till balance = 0
    {
        balance = loan * (1 + interest);
        counter++;
        balance -= payment;
    }

    printf("%d payments", counter);
    return 0;
}