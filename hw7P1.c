#include <stdio.h>
#define MAX 1000

// Assume that there are 1,000 bins numbered from 1 to 1000 and 100 players numbered from 1 to 100. Initially, all bins are empty. A player with id x visits all bins that are a multiple of her id. The player will throw a ball in a bin that she visits if the bin is empty, or pick up a ball if the bin has at least one ball. After all 100 players complete their turn, we want to find the number and ids of the empty bins. Write a C program that mimics this experiment and prints a) the number of empty bins, and b) the ids of the empty bins.

int main()
{
    int bins[MAX], position[1001], i, j, count = 0, k;

    // Setting each index to 0, indicating the bins are empty.
    for (i = 0; i <= MAX; i++)
    {
        bins[i] = 0;
    }

    for (i = 1; i < 101; i++)
    {
        for (j = 1; j < 1001; j++)
        {
            if (j % i == 0)
            {
                if (bins[j] == 0)
                {
                    bins[j]++;
                }
                else
                {
                    bins[j]--;
                }
            }
        }
    }

    k = 0;
    for (i = 1; i < 1001; i++)
    {
        if (bins[i] == 0)
        {
            count++;
            position[k++] = i;
        }
    }

    printf("Number of empty bins: %d\n", count);
    for (i = 0; i < k; i++)
    {
        printf("%d ", position[i]);
    }

    return 0;
}