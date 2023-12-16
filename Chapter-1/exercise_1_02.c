/*
Experiment to find out what happens when printf's argument string contains \c,
where c is some character not listed above.

(page 8 K&R)
*/

#include <stdio.h>

int main()
{
    printf("Hello, world!\c");
    return 0;
}