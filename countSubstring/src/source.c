#include <ctype.h>
#include <string.h>
#include "source.h"

int count_substring(const char *str, const char *substr)
{
    /* BEGIN SOLUTION */
    int count = 0;
    char *ptr;
    while (1) {
        ptr = strstr(str, substr);
        if (ptr) {
            count++;
            str = ptr + 1;
        } else {
            return count;
        }
    }
    /* END SOLUTION */
}
