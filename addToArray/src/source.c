#include "source.h"
#include <stdio.h>
#include <stdlib.h>

int *add_to_array(int *array, int size, int newInt) {
    /*BEGIN SOLUTION*/
    int *newArray = realloc(array, (size + 1) * sizeof(int));
    newArray[size] = newInt;
    return newArray;
    /*END SOLUTION*/
    /*STUB:return NULL;  // replace this */
}

