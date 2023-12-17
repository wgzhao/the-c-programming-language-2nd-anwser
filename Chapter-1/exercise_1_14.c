/*
Write a program to print a histogram of the frequencies of different characters in its input.

(page 24 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 1000 /* max length of a line */
#define MAXCHAR 128 /* max length of a line */

char wl[MAXLINELEN] = "Hello World This is a C programming language";
char cnt[MAXCHAR];

void print_hortin_histogram(int c)
{
    int i = 0;
    printf("%c: ", c);
    for(i=0; i<cnt[c]; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main()
{
    int i, c;
    for(i=0; i<MAXCHAR; i++)
    {
        cnt[i] = -1;
    }
    i = 0;
    while ((c = wl[i++]) != '\0') {
        if (cnt[c] == -1)
            cnt[c] = 1;
        else
            cnt[c] = cnt[c] + 1;
    }

    for (i=0; i<MAXCHAR; i++)
    {
        if (cnt[i] != -1)
            print_hortin_histogram(i);
    }
}