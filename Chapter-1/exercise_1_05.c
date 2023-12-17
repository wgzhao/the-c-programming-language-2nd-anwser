/*
Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
(page 14 K&R)
*/

#include <stdio.h>

int main() 
{
    float fahr, celsius;

    int lower = 0, upper = 300, step = 20;

    printf("Celsius\tFahrenheit\n");
    celsius = upper;
    for(celsius = upper; celsius >= lower; celsius = celsius - step)
    {
        printf("%3.0f\t%6.1f\n", celsius, (9.0 / 5.0) * celsius + 32.0);
    }
    return 0;
}