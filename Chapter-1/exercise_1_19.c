/*
Write a function reverse(s) that reverses the character string. 
Use it to write a program that reverses its input a line at a time.

(page 31 K&R)
*/

#include <stdio.h>

#define MAXLINELEN 1000 /* max length of a line */

char s[MAXLINELEN] = "I wandered lonely as a cloud That floats on high o'er vales and hills";

int main() {
    int i = 0,j=0;
    char result[MAXLINELEN];

    while(s[i++] != '\0');
    i -= 2;
    while(i >= 0) {
        result[j++] = s[i--];
    }
    result[j] = '\0';

    printf("origin   string: %s\n", s);
    printf("reversed string: %s\n", result);
}