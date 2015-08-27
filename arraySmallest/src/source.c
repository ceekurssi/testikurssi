#include "source.h"
#include <limits.h>
#include <stdio.h>

int smallest_number(int array[], int size) {
    /*BEGIN SOLUTION*/
    int smallest = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] < smallest){
            smallest = array[i];
        }
    }
    return smallest;
    /*END SOLUTION*/
    /*STUB: return 0;*/
}
