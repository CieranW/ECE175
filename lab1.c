#include <stdio.h>

int main(void)
{
    // Problem 1
    float number;

    printf("Enter a positive float: \n");
    scanf("%f", &number);
    printf("The previous integer is %d and the next integer is %d.\n", (int)number, (int)number + 1);

    // Problem 2
    int num1, num2;
    int numAdd, numSub, numProd;
    float numDiv;

    printf("Enter two positive integers: \n");
    scanf("%d%d", &num1, &num2);
    numAdd = num1 + num2;
    numSub = num1 - num2;
    numProd = num1 * num2;
    numDiv = (float)num1 / (float)num2;

    printf("Sum: %d, Difference: %d, Product: %d, Division: %f.\n", numAdd, numSub, numProd, numDiv);

    // Problem 3
    int threeDigitNum, twoDigitNum, finalNum;
    int hundredDigitNum, tenDigitNum, oneDigitNum;

    printf("Enter a three digit integer that does not start with 0: \n");
    scanf("%d", &threeDigitNum);

    hundredDigitNum = threeDigitNum / 100; // Divides original number by 100, ex. 345 / 100 = 3.
    twoDigitNum = threeDigitNum % 100;     // Takes og # and finds remainder, ex. 345 % 100 = 45
    tenDigitNum = twoDigitNum / 10;        // Takes the remaining number from above and finds then tenth digit, ex. 45 / 10 = 4.
    oneDigitNum = twoDigitNum % 10;        // Takes the number from line 33 and finds the remainder, ex. 45 % 10 = 5.
    finalNum = hundredDigitNum + tenDigitNum + oneDigitNum;
    // printf("%d\n%d\n%d\n%d\n", hundredDigitNum, twoDigitNum, tenDigitNum, oneDigitNum); //Test line.
    printf("The digit sum of %d is: %d.\n", threeDigitNum, finalNum);

    // Problem 4
    int userSeconds, hour, minutes, seconds;
    int remainingMinutes;

    printf("Enter the number of seconds you want to convert into hours, minutes, seconds: \n");
    scanf("%d", &userSeconds);

    hour = userSeconds / 3600;
    remainingMinutes = userSeconds % 3600;
    minutes = remainingMinutes / 60;
    seconds = remainingMinutes % 60;

    // printf("%d\n%d\n%d\n%d\n", hour, remainingMinutes, minutes, seconds); // Test function.
    printf("%d seconds equal %dh, %dm, and %ds\n", userSeconds, hour, minutes, seconds);

    return 0;
}