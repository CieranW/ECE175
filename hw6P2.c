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
    int num;

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