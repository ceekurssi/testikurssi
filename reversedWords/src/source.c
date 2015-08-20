#include <ctype.h>
#include <string.h>
#include "source.h"

/*BEGIN SOLUTION*/
void reverse_string2(char *str, char *endp)
{
    while (str < endp) {
        char temp = *endp;
        *endp = *str;
        *str = temp;
        str++;
        endp--;
    }
}
/*END SOLUTION*/

void reversed_words(char *p)
{
    /*STUB: (void) p; */
    /*BEGIN SOLUTION*/
    do {
        char *endp = p;
        while (isalnum(*endp) && *endp != 0) {
            endp++;
        }
        reverse_string2(p, endp-1);
        p = endp;
        while (*p && !isalnum(*p))
            p++;
    } while (*p);
    /*END SOLUTION*/
}

