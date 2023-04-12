#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    char nbrhd[20];
    int bedrooms;
    int sqft;
    int rent;
} apt_t;

apt_t *scanApt(FILE *inp, int *numApt_pt);
void printApt(apt_t x);

apt_t *scanApt(FILE *inp, int *numApt_pt)
{
    apt_t *apt = (apt_t *)malloc(*numApt_pt * sizeof(apt_t));
    for (int i = 0; i < *numApt_pt; i++)
    {
        fscanf(inp, "%s%d%d%d", apt[i].nbrhd, &apt[i].bedrooms, &apt[i].sqft, &apt[i].rent);
    }
    return apt;
}

void printApt(apt_t x)
{
    printf("%s, %d, %d, %d\n", x.nbrhd, x.bedrooms, x.sqft, x.rent);
}
int main()
{
    FILE *inp;
    inp = fopen("apts.txt", "r");
    int numApt_pt;

    fscanf(inp, "%d%*c", &numApt_pt);
    apt_t *apt = scanApt(inp, &numApt_pt);

    for (int i = 0; i < numApt_pt; i++)
    {
        if (apt[i].rent <= 1500 && strcmp(apt[i].nbrhd, "UA") == 0)
        {
            printApt(apt[i]);
        }
    }

    fclose(inp);
    return 0;
}
