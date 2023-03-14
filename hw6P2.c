#include <stdio.h>
void smallestInt(FILE *inp, int *pmin1, int *pmin2);
// pmin1 is the smalles number and pmin2 is the second smallest number, so pmin1 should be less than pmin2.

int main(void)
{
    int pmin1, pmin2;
    FILE *inp;
    inp = fopen("data.txt", "r");

    smallestInt(inp, &pmin1, &pmin2);
    printf("Smallest number: %d\n", pmin1);
    printf("Second smallest number: %d\n", pmin2);

    fclose(inp);

    return 0;
}

void smallestInt(FILE *inp, int *pmin1, int *pmin2)
{
    // Initializes the temp variable (num), and the two min values so that there isn't an error thrown during a unit test. If failed to initialise, a unit test would show that min1 and min2 would be 0 and 1 (I think).
    int num = 0;
    fscanf(inp, "%d", &num);
    *pmin1 = num;
    *pmin2 = num;

    while (!feof(inp))
    {
        fscanf(inp, "%d", &num);
        if (num <= *pmin1)
        {
            *pmin2 = *pmin1;
            *pmin1 = num;
        }
        else if (num <= *pmin2 && num != *pmin1)
        {
            *pmin2 = num;
        }
    }
}