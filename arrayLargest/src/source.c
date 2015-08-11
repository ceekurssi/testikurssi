#include "source.h"
#include <stdio.h>

int largest_number(int* array) {
    /*BEGIN SOLUTION*/
    int largest = -1;
    while (*array != -1) {
        if (*array > largest) {
            largest = *array;
        }
        array++;
    }
    return largest;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
