#include <stdio.h>
#include <string.h>

void ReadBikeData(char Names[][13], int BikeData[][3]);
void CalculateBikeRating(int BikeData[][3], double Score[], char Ratings[][3]);

void ReadBikeData(char Names[][13], int BikeData[][3])
{
    int i, j;
    FILE *input;
    input = fopen("MX_Bike_Data.txt", "r");

    while (!feof(input))
    {
        for (i = 0; i < 12; i++)
        {
            fscanf(input, "%s", Names[i]);

            for (j = 1; j < 4; j++)
            {
                fscanf(input, "%d", &BikeData[i][j - 1]);
            }
        }
    }

    fclose(input);
}

void CalculateBikeRating(int BikeData[][3], double Score[], char Ratings[][3])
{
    int i;

    for (i = 0; i < 12; i++)
    {
        Score[i] = 100 * (BikeData[i][0] - 2000) * ((double)BikeData[i][1] / (double)BikeData[i][2]) - 200;

        if (Score[i] >= 65)
        {
            strcpy(Ratings[i], "A+");
        }
        else if (Score[i] >= 60 && Score[i] <= 64)
        {
            strcpy(Ratings[i], "A");
        }
        else if (Score[i] >= 55 && Score[i] <= 59)
        {
            strcpy(Ratings[i], "A-");
        }
        else if (Score[i] >= 50 && Score[i] <= 54)
        {
            strcpy(Ratings[i], "B+");
        }
        else if (Score[i] >= 45 && Score[i] <= 49)
        {
            strcpy(Ratings[i], "B");
        }
        else if (Score[i] > 39 && Score[i] <= 44)
        {
            strcpy(Ratings[i], "B-");
        }
        else if (Score[i] >= 35 && Score[i] <= 39)
        {
            strcpy(Ratings[i], "C+");
        }
        else if (Score[i] >= 30 && Score[i] <= 34)
        {
            strcpy(Ratings[i], "C");
        }
        else if (Score[i] >= 25 && Score[i] <= 29)
        {
            strcpy(Ratings[i], "C-");
        }
        else if (Score[i] >= 20 && Score[i] <= 24)
        {
            strcpy(Ratings[i], "D+");
        }
        else if (Score[i] >= 15 && Score[i] <= 19)
        {
            strcpy(Ratings[i], "D");
        }
        else if (Score[i] >= 10 && Score[i] <= 14)
        {
            strcpy(Ratings[i], "D-");
        }
        else if (Score[i] >= 5 && Score[i] <= 9)
        {
            strcpy(Ratings[i], "F");
        }
    }
}

int main()
{
    char Names[13][13], Ratings[13][3];
    int BikeData[13][3];
    double Score[13];

    ReadBikeData(Names, BikeData);
    CalculateBikeRating(BikeData, Score, Ratings);

    printf("Bike Name:\tScore:\tRating:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s\t%.2f\t%s\n", Names[i], Score[i], Ratings[i]);
    }

    return 0;
}