#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int hr;
    int min;
    int sec;
} runner;

void readEntry(runner *pt, FILE *inp);
runner fastestPace(runner race[], int size);

void readEntry(runner *pt, FILE *inp)
{
    fscanf(inp, "%s%d%*c", pt->name, &pt->sec);
}

runner fastestPace(runner race[], int size)
{
    runner nameTime;
    int i, fastest = 10000;

    // Searches through to find the fastest time
    for (i = 0; i < size; i++)
    {
        if (race[i].sec < fastest)
        {
            fastest = race[i].sec;
            nameTime = race[i];
        }
    }

    // Converts the time from seconds into hr, min and takes the total sec minus the hr and min to find the remaining sec
    nameTime.hr = fastest / 3600;
    nameTime.min = (fastest % 3600) / 60;
    nameTime.sec = fastest - (nameTime.hr * 3600 + nameTime.min * 60);

    return nameTime;
}
int main()
{
    FILE *inp = fopen("racedata.txt", "r");
    runner race[20], pt, fastest;
    int size = 0;

    while (!feof(inp))
    {
        // Reads a single entry to the array. Counts the size of the array based on how many times it takes to scan before reaching the end of file
        readEntry(&pt, inp);
        race[size] = pt;
        size++;
    }

    fastest = fastestPace(race, size);
    printf("The fastest runner is %s who ran the marathon in %d hours %d mins and %d secs.\n", fastest.name, fastest.hr, fastest.min, fastest.sec);

    return 0;
}