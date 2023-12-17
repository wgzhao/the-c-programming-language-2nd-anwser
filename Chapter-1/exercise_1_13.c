/*
Write a program to print a histogram of the lengths of words in its input.
 It is easy to draw the histogram with the bars horizontal; 
 a vertical orientation is more challenging.
*/

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXWORDLEN 20 /* max length of a word */
#define MAXLINELEN 1000 /* max length of a line */

char wl[MAXLINELEN] = "Hello World This is a C programming language";

void print_hist(int len, int pos)
{
    int i;

    for(i= pos; i< pos + len; i++) {
        printf("%c", wl[i]);
    }

    printf("%s", ":");

    for(i=0; i<len; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main()
{
    int state = OUT;
    int cnt[MAXWORDLEN];

    int i=0;
    int j=0;
    int c;

    i = 0;
    while((c = wl[i++]) != '\0')
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            j++;
        } else if (state == OUT) {
            state = IN;
            cnt[j] = 1;
        } else {
            cnt[j] = cnt[j] + 1;
        }
    }
    // print the histogram
    int cur_pos = 0;
    for(i=0; i<=j; i++)
    {
       print_hist(cnt[i], cur_pos);
       cur_pos += cnt[i] + 1;
    }

    return 0;
}