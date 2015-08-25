#include <stdio.h>
#include "source.h"

/*Read integers from user until 0, incorrect integer or end-of-file and return the maximum of these values.
 * Return 0, if user didn't enter any correct integer.*/

int main(void) {
    printf("%d\n", maximum_integer());
    return 0;
}
