/*
How would you test the word count program ?
What kinds of input are most likely to uncover bugs if there are any ?
*/

#include <stdio.h>

#define MAXLINE 1000


void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

int count_word(char s[])
{
    int i, word_cnt=0;
    int state = 0; // 0: out of word, 1: in word
    for (i=0; s[i]!='\0';i++){
        if ( s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        {
            state = 0;
        } else if (state == 0) {
            state = 1;
            word_cnt++;
        }
    }
    return word_cnt;
}

int main() 
{
    // test no input, should be 0
    char line[MAXLINE];
    printf("The  number of string('%s') words is %d\n", line, count_word(line));
    
    // test no words , just newline
    copy("\n", line);
    printf("The  number of string('%s') words is %d\n", line, count_word(line));
    
    //no words, just blanks and tabs
    copy("  \t\t  ", line);
    printf("The  number of string('%s') words is %d\n", line, count_word(line));

    // one word per line, no blanks and tabs
    copy("hello\nworld\n", line);
    printf("The  number of string('%s') words is %d\n", line, count_word(line));

    // workd starting at the beginning of the line
    copy("hello world", line);
    printf("The  number of string('%s') words is %d\n", line, count_word(line));

    // word starting after some blanks
    copy("  hello world", line);
    printf("The  number of string('%s') words is %d\n", line, count_word(line));
}