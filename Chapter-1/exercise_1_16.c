/*
Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, 
and as much as possible of the text.

(page 30 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 1000 /* max length of a line */
#define MAXLINES 10 /* max number of lines */

// read a line into s, return length
int get_line(char s[]);
void copy(char[], char[]);

int main()
{
    int curr_line_len = 0; /* current line length */
    int curr_max_len = 0; /* current max length */
    char line[MAXLINES][MAXLINELEN]= {
        "I wandered lonely as a cloud",
        "That floats on high o'er vales and hills,",
        "When all at once I saw a crowd,",
        "A host, of golden daffodils;",
        "Beside the lake, beneath the trees,",
        "Fluttering and dancing in the breeze.",
        "Continuous as the stars that shine",
        "And twinkle on the milky way,",
        "They stretched in never-ending line",
        "Along the margin of a bay"
        }; /* current input line */
    char longest[MAXLINELEN]; /* longest line saved here */

    for (int i = 0; i < MAXLINES; ++i)
    {
        curr_line_len = get_line(line[i]);
        if (curr_line_len > curr_max_len)
        {
            curr_max_len = curr_line_len;
            copy(line[i], longest);
        }
    }
    printf("Longest line:\n%s\n", longest);
}

int get_line(char s[])
{
    int i = 0;
    while ((s[i++]) != '\0');
    return i;
}

void copy(char from[], char to[])
{
    int i=0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}