/*
Modify the temperature conversion program to print a heading above the table.

(page 13 K&R)
*/

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;   // step size

    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0); // 5/9 is 0 because both operands are integers
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}