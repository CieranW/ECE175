// Convert Celsius to Farenheit and vice versa

#include <stdio.h>

int main(void)
{
    float temp_farenheit, temp_celsius;

    printf("What is the temperature in Farenheit? \n");
    scanf("%f", &temp_farenheit);
    temp_celsius = (temp_farenheit - 32.0) / 1.8;
    printf("The temperature in Celsius is: \n");
    printf("%f\n", temp_celsius);

    return 0;
}