/*
Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
say every n columns. Should n be a variable or a symbolic parameter?

(page 34 K&R)
*/

#include <stdio.h>

#define TABSTOP 8 // tab increment size
#define MAXLINELEN 1000 /* max length of a line */

char s[MAXLINELEN] = "I wandered lonely as a cloud\tThat \tfloats\t on high o'er\t vales and hills\nWrite a program\n detab that \treplaces tabs in \tthe\n input with the\n proper \tnumber";

int main()
{
    int c, nb, pos;

    nb = 0;
    pos = 1;
    int i =0;
    while((c = s[i]) != '\0') {
        if (c == '\t') {
            nb = TABSTOP - (pos - 1) % TABSTOP;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
        ++i;
    }
    return 0;
}