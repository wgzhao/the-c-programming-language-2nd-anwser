/*
Write a program to print all input lines that are longer than 80 characters.

(page 31 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 1000 /* max length of a line */
#define MAXLINES 10     /* max number of lines */

char line[MAXLINES][MAXLINELEN] = {
    "I wandered lonely as a cloud That floats on high o'er vales and hills",
    "When all at once I saw a crowd,A host, of golden daffodils;",
    "Beside the lake, beneath the trees, Fluttering and dancing in the breeze.",
    "Continuous as the stars that shine And twinkle on the milky way,They stretched in never-ending line",
    "Along the margin of a bay"
    }; /* current input line */

int get_line(char s[])
{
    int i = 0;
    while ((s[i++]) != '\0')
        ;
    return i;
}

int main()
{
    int i;
    for (i = 0; i < MAXLINES; ++i)
    {
        if (line[i][0] == '\0')
            break;
        if (get_line(line[i]) > 80)
            printf("%s\n", line[i]);
    }

    return 0;
}