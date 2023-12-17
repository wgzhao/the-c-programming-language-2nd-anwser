/*
Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

(page 20 K&R)
*/

#include<stdio.h>

#define BEGINBLANK 0 

int main() 
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' '){
            while ((c = getchar()) == ' ') {
                //skip the consequent blanks
            }
            putchar(c);
        }
    }
}