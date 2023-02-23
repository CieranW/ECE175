#include <stdio.h>

char Decrypt(char letter)
{
    FILE *codekey = fopen("substitution.txt", "r");
    char dLetter = '1';
    int i = -1;

    if (codekey == NULL)
    {
        printf("substitution.txt couldn't be opened.\n");
        return -1;
    }

    while (letter != dLetter)
    {
        fscanf(codekey, "%c", &dLetter);
        i++;
    }
    fclose(codekey);
    return 'a' + i;
}

int main()
{
    FILE *encrypted = fopen("encrypted.txt", "r");
    FILE *decrypted = fopen("decrypted.txt", "w");
    char letter;

    if (encrypted == NULL)
    {
        printf("encrypted.txt couldn't be opened.\n");
        return -1;
    }
    while (!feof(encrypted))
    {
        fscanf(encrypted, "%c", &letter);
        if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter - 'A' + 'a';
            letter = Decrypt(letter);
            letter = letter - 'a' + 'A';
            fprintf(decrypted, "%c", letter);
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            fprintf(decrypted, "%c", Decrypt(letter));
        }
        else
        {
            fprintf(decrypted, "%c", letter);
        }
    }
    fclose(encrypted);
    fclose(decrypted);
    return 0;
}
