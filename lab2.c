#include <stdio.h>
#include <math.h>

int main(void)
{
    // Problem 1
    // int num1, num2, numSolution;

    // printf("Enter two integers: \n");
    // scanf("%d %d", &num1, &num2);

    // numSolution = (-num2) / num1;

    // if (num1 == 0)
    // {
    //     printf("Solution is undefined.\n");
    // }
    // else
    // {
    //     printf("x = %d\n", numSolution);
    // }

    // Problem 2
    // float userIncome;
    // int owedTax;

    // printf("Enter your income: \n");
    // scanf("%f", &userIncome);

    // if (userIncome <= 12000)
    // {
    //     owedTax = 0;
    //     printf("Your owed tax is: %d\n", owedTax);
    // }
    // else if (userIncome > 12000 && userIncome <= 40000)
    // {
    //     owedTax = (12000 * 0) + ((userIncome - 12000) * 0.15);
    //     printf("Your owed tax is: %d\n", owedTax);
    // }
    // else if (userIncome > 40000 && userIncome <= 100000)
    // {
    //     owedTax = (28000 * 0.15) + ((userIncome - 40000) * 0.3);
    //     printf("Your owed tax is: %d\n", owedTax);
    // }
    // else if (userIncome > 100000)
    // {
    //     owedTax = (60000 * 0.3) + (userIncome * 0.4);
    //     printf("Your owed tax is: %d\n", owedTax);
    // }

    // // Problem 3
    double sedanCost = 20000, suvCost = 35000, sedanOrderNum, suvOrderNum, totalOrderNum, potentialTotalCost, actualTotalCost;

    printf("Enter number of Sedans and SUVs you would like to order: \n");
    scanf("%lf %lf", &sedanOrderNum, &suvOrderNum);

    totalOrderNum = sedanOrderNum + suvOrderNum;
    potentialTotalCost = (sedanCost * sedanOrderNum) + (suvCost * suvOrderNum);
    // printf("%lf %lf", totalOrderNum, potentialTotalCost);

    if (potentialTotalCost > 20000000)
    {
        actualTotalCost = potentialTotalCost * 0.8;
        printf("The total cost for %.0lf Sedans and %.0lf SUVs is: $%.1lf\n", sedanOrderNum, suvOrderNum, actualTotalCost);
    }
    else if (potentialTotalCost > 10000000 || totalOrderNum > 300)
    {
        actualTotalCost = potentialTotalCost * 0.9;
        printf("The total cost for %.0lf Sedans and %.0lf SUVs is: $%.1lf\n", sedanOrderNum, suvOrderNum, actualTotalCost);
    }
    else
    {
        actualTotalCost = potentialTotalCost;
        printf("The total cost for %.0lf Sedans and %.0lf SUVs is: $%.1lf\n", sedanOrderNum, suvOrderNum, actualTotalCost);
    }
    return 0;
}