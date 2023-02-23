#include <stdio.h>
#include <math.h>
#include <string.h>
#define closeEnough(a, b) (fabs((a) - (b)) < 1e-10 * (fabs(a) + fabs(b))) ? 1 : 0

int compareArrays(double a[], double b[], int n)
{
    int ii;
    for (ii = 1; ii <= n; ii++)
    {
        if (a[ii] != b[ii])
            return 0;
        // better:
        // if(fabs(a[ii]-b[ii]) < 1e-10 * (fabs(a[ii]) + fabs(b[ii]))) {
        // with the appropriate tolerance
    }
    return 1;
}

int main()
{
    // Problem 1
    FILE *triNum;
    triNum = fopen("numbers.txt", "r");
    int numInp, testNum; // actualTriNum;

    if (NULL == triNum)
    {
        printf("numbers.txt not found");
        return -1;
    }

    while (!feof(triNum))
    {
        fscanf(triNum, "%d", &numInp);
        printf("The set of triangular number is: ");
        while (numInp > 0)
        {
            testNum = 2 * numInp;
            for (int i = 0; i <= testNum; i++)
            {
                long int j = (pow(i, 2) + i);
                if (testNum == j)
                {
                    printf("%d ", numInp);
                }
            }
        }
    }
    fclose(triNum);

    // Problem 2
    FILE *friDat;
    int userNum, numScan;
    int count = 0;

    friDat = fopen("Fridays_Data.dat", "r");

    if (NULL == friDat)
    {
        printf("Friday_Data.dat can't be opened.");
        return -1;
    }
    printf("Count the number of integers above what threshold?\n");
    scanf("%d", &userNum);

    while (!feof(friDat))
    {
        fscanf(friDat, "%d", &numScan);
        if (numScan >= userNum)
        {
            count += 1;
        }
    }
    if (userNum < 0)
    {
        count -= 1;
    }
    printf("The number of integers >= %d was found to be %d\n", userNum, count);

    fclose(friDat);

    // // Problem 3
    // FILE *flight;
    // flight = fopen("flights.txt", "r+");
    // char flightDetails[7];
    // char updateFlightStat[1];
    // char userFlightStatus[7];

    // int userFlightStatus, flightDetails;
    // if (flight == NULL)
    // {
    //     printf("flights.txt could not be opened.\n");
    //     return -1;
    // }

    // printf("Enter the airline and flight number: \n");
    // scanf(" %c", userFlightStatus);

    // userFlightStatus = userFlightStatus / 100;
    // flightDetails = flightDetails / 100;
    // while (!feof(flight))
    // {
    //     fscanf(flight, " %c", flightDetails);
    //     double userFlightStatus, flightDetails;
    //     // if (closeEnough(userFlightStatus, flightDetails))
    //     if (userFlightStatus == flightDetails)
    //     {
    //         // char flightDetails[7], userFlightStatus[7];
    //         int length = strlen(flightDetails);
    //         int flightStatus = length - 1;

    //         switch ((char)flightStatus)
    //         {
    //         case 'D':
    //             printf("Flight %s has departed\n", userFlightStatus);
    //             break;

    //         case 'L':
    //             printf("Flight %s has landed\n", userFlightStatus);
    //             break;

    //         case 'C':
    //             printf("Flight %s was cancelled\n", userFlightStatus);
    //             break;
    //         }
    //     }
    //     else
    //     {
    //         char userFlightStatus[7];
    //         printf("%s was not found. What is the status?(D/L/C)\n", userFlightStatus);
    //         scanf(" %c", updateFlightStat);
    //         fprintf(flight, "%s %s", userFlightStatus, updateFlightStat);
    //     }
    // }
    // fclose(flight);
    return 0;
}
