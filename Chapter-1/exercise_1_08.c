/*
Write a program to count blanks, tabs and newlines.

(Page 20 K&R)
*/

#include <stdio.h>

int main()
{

    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++blanks;
        }
        else if(c == '\t')
        {
            ++tabs;
        }
        else if(c == '\n')
        {
            ++newlines;
        }
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
    return 0;
}