// modify (04/03/2019) by Kay to get the correct value of mean

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    double mantissa;
    int exponent;
} sciNotation;

sciNotation convert(double num);                 // converts a double to scientific notation
sciNotation meanVal(sciNotation arr[], int len); // computes the mean value of the array and returns mean in scientific notation
void printVal(sciNotation *num);                 // prints a number in scientific notation

int main(void)
{
    // main function code here
    sciNotation convertedNum[10], meanNum;
    double num;
    bool loop = false;
    char answerloop;
    int i = 0;

    while (loop != true)
    {
        printf("Enter a value: \n");
        scanf("%lf", &num);

        convertedNum[i] = convert(num);
        printVal(&convertedNum[i]);
        printf("Do you want to enter another value (y/n)?\n");
        scanf(" %c", &answerloop);
        i++;
        if (answerloop == 'y')
        {
            loop = false;
        }
        else if (answerloop == 'n')
        {
            loop = true;
        }
    }

    if (loop == true)
    {
        meanNum = meanVal(convertedNum, i);
        printVal(&meanNum);
    }

    return 0;
}

sciNotation convert(double num)
{
    // conversion function.
    sciNotation sciConvert;
    int i = 0;

    if (num > 9)
    {
        while (num > 10)
        {
            num = num / 10;
            i++;
        }
    }
    else if (num < 1)
    {
        while (num < 1 && num > 0)
        {
            num = num * 10;
            i--;
        }
    }

    sciConvert.mantissa = num;
    sciConvert.exponent = i;

    return sciConvert;
}

sciNotation meanVal(sciNotation arr[], int len)
{
    // mean computation function
    sciNotation mean;
    int tempArray[len];
    double tempVal = 0;

    for (int i = 0; i < len; i++)
    {
        tempArray[i] = arr[i].mantissa * pow(10, arr[i].exponent);
    }

    for (int i = 0; i < len; i++)
    {
        tempVal += tempArray[i];
    }

    tempVal /= len;

    int j = 0;
    while (tempVal > 10)
    {
        tempVal = tempVal / 10;
        j++;
    }

    mean.mantissa = tempVal;
    mean.exponent = j;

    return mean;
}

void printVal(sciNotation *num)
{
    // printing function
    printf("%lf", num->mantissa);
    if (num->exponent <= 0)
    {
        printf("E%d\n", num->exponent);
    }
    else
    {
        printf("E+%d\n", num->exponent);
    }
}
