#include "source.h"
#include <stdio.h>
#include <stdlib.h>

int* dynamic_reader(int size) {
    /*BEGIN SOLUTION*/
    int *array = malloc(size * sizeof (int));
    int i = 0;
    while (i < size) {
        if (scanf("%d", &array[i]) == 1) {
            i++;
        }
    }
    return array;
    /*END SOLUTION*/
    /*STUB:return NULL;  // replace this */
}
