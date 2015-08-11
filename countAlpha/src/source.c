#include <ctype.h>
#include "source.h"

int count_alpha(const char *str) {
    /* BEGIN SOLUTION */
    int count = 0;
    while (*str) {
        if (isalpha(*str)){
            count++;
        }
        str++;
    }
    return count;
    /* END SOLUTION */
}

