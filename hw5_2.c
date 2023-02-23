#include <stdio.h>
#include <math.h>

long int IntToBinary(int integerValue)
{
    long long int powerValue = 0, binNumber = 0;
    while (integerValue > 0)
    {
        int remainder = integerValue % 2;                   // Sets remainder = 0 or 1 depending on the divisiblity.
        long long int temporaryValue = pow(10, powerValue); // To change digit value, ex. from one to ten to hundred, etc.
        binNumber += remainder * temporaryValue;            // Sets binary to 0 or 1 depending on remainder value.
        powerValue++;                                       // Increments power by 1 for each run of the loop.
        integerValue /= 2;                                  // Divides the initial value by 2 to obtain the rest of the number. Ex. intvalue = 6, new intValue = 3.
    }
    return binNumber;
}

int main()
{
    int integerValue;

    scanf("%d", &integerValue);
    printf("%ld\n", IntToBinary(integerValue));

    return 0;
}