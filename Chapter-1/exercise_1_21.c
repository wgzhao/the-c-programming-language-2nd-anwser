/*
Write the program entab that replaces strings of blanks by the minimum number 
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which 6ould be given preference?

(page 34 K&R)
*/

#include <stdio.h>

#define TABSTOP 8 // tab increment size
#define MAXLINELEN 1000 /* max length of a line */

char s[MAXLINELEN] = "I wandered lonely as a cloud           That floats on high o'er vales and hills\nWrite a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?";

int main()
{
    int c, nb, nt, pos;

    nb = 0;
    nt = 0;
    pos = 1;
    int i =0;
    while((c = s[i]) != '\0') {
        if (c == ' ') {
            if (pos % TABSTOP != 0) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            while (nt > 0) {
                putchar('\t');
                --nt;
            }
            if (c == '\t') {
                nb = 0;
            } else {
                while (nb > 0) {
                    putchar(' ');
                    --nb;
                }
            }
            putchar(c);
            if (c == '\n') {
                pos = 1;
            } else if (c == '\t') {
                pos += TABSTOP - (pos - 1) % TABSTOP;
            } else {
                ++pos;
            }
        }
        ++i;
    }
    return 0;
}