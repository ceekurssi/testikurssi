#include <stdio.h>
#include "source.h"

/*Write a function int replace_blanks(), that replaces all occurrences of the blank character by *.
 * Function should return 0, if successful and -1 if there was an error. */

int main() {
    int ret = replace_blanks();
    printf("%d\n", ret);
    return 0;
}
