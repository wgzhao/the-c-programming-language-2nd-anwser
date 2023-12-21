/*
Write a program to "fold" long input lines into two or more shorter lines
after the last non-blank character that occurs before the n-th column of input.
Make sure your program does something intelligent with very long lines,
and if there are no blanks or tabs before the specified column.

(page 34 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 2000 /* max length of a line */
#define MAXCOL 80
#define TABSTOP 8

char s[MAXLINELEN] = "I wandered lonely as a cloud That floats on high o'er vales and hills\n  When all at once I saw a crowd, A host, of golden daffodils\n  Beside the lake, beneath the trees, Fluttering and dancing in the breeze.\nContinuous as the stars that shine And twinkle on the milky way,They stretched in never-ending line\nAlong the margin of a bay   \nWrite a program to fold long input lines into two or more shorter lines after the last non-blank character    \nthat occurs before the n-th column of input. Make sure your program does something intelligent with very long lines\nand if there are no blanks or tabs before the specified column   "; /* current input line */

int word_length(int start_pos)
{
    int cnt = 0;
    while (s[start_pos] != ' ' && s[start_pos] != '\t' && s[start_pos] != '\n')
    {
        if (s[start_pos] == '\t')
        {
            cnt += TABSTOP;
        }
        else
        {
            cnt++;
        }
        start_pos++;
    }
    return cnt;
}

int blank_length(int start_pos)
{
    int cnt = 0;
    int tmp_pos = start_pos;
    while (s[start_pos] == ' ' || s[start_pos] == '\t')
    {
        if (s[start_pos] == '\t')
        {
            cnt += TABSTOP;
        }
        else
        {
            cnt++;
        }
        start_pos++;
    }
    return cnt;
}

void print_n_chars(int start_pos, int len)
{
    for (int i = 0; i < len; i++)
    {
        putchar(s[start_pos + i]);
    }
}

int main()
{
    int c, pos;
    int i = 0;
    int cur_line_length = 0;
    int len;
    while (s[i] != '\0')
    {
        if (s[i] == ' ' || s[i] == '\t')
        {
            len = blank_length(i);
            if (cur_line_length + len < MAXCOL)
            {
                if (cur_line_length == 0) {
                    // first print in new line, skip leading blanks

                } else {
                    print_n_chars(i, len);
                    cur_line_length += len;
                }
                i += len;
            }
            else
            {
                // ignore trail blank
                putchar('\n');
                cur_line_length = 0;
            }
        }
        else if (s[i] == '\n')
        {
            putchar('\n');
            cur_line_length = 0;
            i++;
        }
        else
        {
            len = word_length(i);
            if (cur_line_length + len < MAXCOL)
            {
                print_n_chars(i, len);
                i += len;
                cur_line_length += len;
            }
            else
            {
                // print in the next line
                putchar('\n');
                print_n_chars(i, len);
                cur_line_length = len;
                i += len;
            }
        }
    }
}