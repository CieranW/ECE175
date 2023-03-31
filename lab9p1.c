#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool WordReverse(char input[100]);

bool WordReverse(char input[100])
{
    int len, i, temp;
    char reversed[100];

    len = strlen(input);
    // reversed = strrev(input);

    for (i = 0; i < len; i++)
    {
        // temp variable use to temporary hold the string
        temp = input[i];
        reversed[i] = input[len - i - 1];
        reversed[len - i - 1] = temp;
    }
    printf("%s\t%s\n", input, reversed);
    if (strcmp(reversed, input) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    FILE *inp;
    FILE *out;
    inp = fopen("Palindrome_Input.txt", "r");
    out = fopen("Palindrome_Output.txt", "w");
    char input[100];
    bool reverse = false;

    while (!feof(inp))
    {
        fscanf(inp, "%s", input);
        reverse = WordReverse(input);

        if (reverse == true)
        {
            fprintf(out, "%s\n", input);
        }
    }

    return 0;
}