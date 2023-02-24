#include <stdio.h>

int main(void)
{
    double loan, payment, interest, newBalance;

    scanf("%lf %lf %lf", &loan, &payment, &interest);

    newBalance = (loan * interest) + loan;

    return 0;
}