#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Name[20];
    double TotalArea;
    double WaterArea;
    double LandArea;
    int Population;
    int Rank;
} State;

void scanState(State *x, FILE *in);
void printState(State *x);
void sortState(State x[], int size);
void selectionState(State x[], int size);

void scanState(State *x, FILE *in)
{
    for (int i = 0; i < 10; i++)
    {
        fscanf(in, "%d%s%d%lf%lf", &x[i].Rank, x[i].Name, &x[i].Population, &x[i].TotalArea, &x[i].WaterArea);
    }
}

void printState(State *x)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d. %s %d %.2lf %.2lf %.2lf\n", x[i].Rank, x[i].Name, x[i].Population, x[i].TotalArea, x[i].WaterArea, x[i].LandArea);
    }
}

void sortState(State x[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        x[i].LandArea = x[i].TotalArea - x[i].WaterArea;
    }
}

void selectionState(State x[], int size)
{
    // selection sort
    int i, j;
    int min;
    State temp;

    for (i = 0; i < size; i++)
    {
        min = i; // start searching from currently unsorted
        for (j = i; j < size; j++)
        {
            if (x[j].LandArea > x[min].LandArea) // if found a smaller element
                min = j;                         // move it to the front
        }
        temp = x[i];
        x[i] = x[min];
        x[min] = temp;
    }
}

int main()
{
    int i, size = 10;
    FILE *inp;
    inp = fopen("StateData.txt", "r");
    State array[10];

    scanState(array, inp);
    sortState(array, size);
    selectionState(array, size);
    printState(array);

    fclose(inp);
    return 0;
}