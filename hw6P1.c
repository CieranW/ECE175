#include <stdio.h>
void distConverter(int d, int *p_y, int *p_f, int *p_i);

int main(void)
{
    FILE *inp;
    inp = fopen("dist.txt", "r");
    int d, p_y, p_f, p_i;

    while (!feof(inp))
    {
        fscanf(inp, "%d", &d);
    }

    DistConverter(d, &p_y, &p_f, &p_i);
    printf("%d\t%d\t%d\n", p_y, p_f, p_i);

    fclose(inp);

    return 0;
}

void DistConverter(int d, int *p_y, int *p_f, int *p_i)
{
    *p_f = d / 12;
    *p_i = d % 12;
    *p_y = *p_f / 3;
    *p_f = *p_f % 3;
}