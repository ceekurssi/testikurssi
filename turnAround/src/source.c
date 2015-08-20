#include <ctype.h>
#include <string.h>
#include "source.h"

void turn_around(char *p)
{
    /*STUB: (void) p; */
    /*BEGIN SOLUTION*/
    int endi = strlen(p) - 1;
    int i = 0;
    while (i < endi) {
        char temp = p[endi];
        p[endi] = p[i];
        p[i] = temp;
        i++;
        endi--;
    }
    /*END SOLUTION*/
}
