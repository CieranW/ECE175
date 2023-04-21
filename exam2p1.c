// Symmetric Arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int readFile(int data[], int size, FILE *inp);
bool symmetricArrays(int data[], int size, float *pivot);

int readFile(int data[], int size, FILE *inp)
{

    while (!feof(inp))
    {
        fscanf(inp, "%d", &data[size]);
        size++;
    }
    return size;
}

bool symmetric(int data[], int size, float *pivot)
{
    bool symmetry = false;

    // Compares the first and second half of the array to determine if the values match
    for (int i = 0; i < size; i++)
    {
        if (data[i] == data[size - 1 - i])
        {
            symmetry = true;
        }
        else
        {
            symmetry = false;
            break;
        }
    }
    // If the array is symmetric, finds the value where the data is mirrored
    if (symmetry == true)
    {
        *pivot = (data[(size - 1) / 2] + data[((size - 1) / 2) + 1]) / 2;
    }

    return symmetry;
}

int main()
{
    // Obtains the name of the file from user input
    char userFilename[50], comma[20];
    printf("Enter the name of the data file:\n");
    scanf("%s", userFilename);

    FILE *inp = fopen(userFilename, "r");
    int data[20], size = 0, i, j;
    float pivot;
    bool symmetry = false;

    size = readFile(data, size, inp);
    symmetry = symmetric(data, size, &pivot);

    // Assigns the number of commas needed
    for (i = 0; i < size - 1; i++)
    {
        comma[i] = ',';
    }

    // Prints out the name of the file and its contents
    printf("%s:", userFilename);

    for (i = 0; i < size; i++)
    {
        printf(" %d%c", data[i], comma[i]);
    }
    printf("\n");

    // Prints out the array in array format and if it's symmetric or not
    printf("Array [");
    for (i = 0; i < size; i++)
    {
        printf(" %d%c", data[i], comma[i]);
    }
    printf("] is ");
    if (symmetry == true)
    {
        printf("symmetric with a pivot value of %.1f.\n", pivot);
    }
    else
    {
        printf("is not symmetric.\n");
    }

    fclose(inp);
    return 0;
}