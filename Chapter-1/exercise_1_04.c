/*
Write a program to print the corresponding Celsius to Fahrenheit table.

(page 13 K&R)
*/

#include <stdio.h>

int main() 
{
    float fahr, celsius;

    int lower = 0, upper = 300, step = 20;

    printf("Celsius\tFahrenheit\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0; // 9/5 is 1 because both operands are integers
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}