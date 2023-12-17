/*
Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

(page 31 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 1000 /* max length of a line */
#define MAXLINES 11     /* max number of lines */

char line[MAXLINES][MAXLINELEN] = {
    "I wandered lonely as a cloud           ",
    "That floats on high o'er vales and hills,  ",
    "When all at once I saw a crowd,  ",
    "A host, of golden daffodils;",
    "       ",
    "Beside the lake, beneath the trees,",
    ""
    "Fluttering and dancing in the breeze.  ",
    "Continuous as the stars that shine  ",
    "And twinkle on the milky way,  ",
    "They stretched in never-ending line  ",
    "Along the margin of a bay  "
    }; /* current input line */

int main()
{
    int i, j;
    int cur_non_blank_trail_pos = 0;

    int c;
    for (i = 0; i < MAXLINES; i++)
    {
        j = 0;
        cur_non_blank_trail_pos = 0;
        while ((c = line[i][j]) != '\0')
        {
            if (c == ' ' || c == '\t')
            {
                //find the last non-blank or non-tab character until the end of the line
                while ((c = line[i][j++]) != '\0')
                {
                    if (c != ' ' && c != '\t')
                    {
                        cur_non_blank_trail_pos = j;
                        break;
                    } 
                }
            }
            else
            {
                j++;
                cur_non_blank_trail_pos = j;
            }
        } // end while loop
        line[i][cur_non_blank_trail_pos] = '\0';
        //print line
        printf("'%s'\n", line[i]);
    }
    return 0;
}