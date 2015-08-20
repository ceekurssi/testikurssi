#include <ctype.h>
#include <string.h>
#include "source.h"

int is_palindrome(const char *p)
{
    /*STUB: (void) p; */
    /*BEGIN SOLUTION*/
    int endi = strlen(p) - 1;
    int i = 0;
    while (i < endi) {
        if (p[i] != p[endi])
            return 0;
        i++;
        endi--;
    }
    return 1;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
