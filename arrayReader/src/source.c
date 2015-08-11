#include "source.h"
#include <stdio.h>

int array_reader(int* array, int maxSize) {
    /*BEGIN SOLUTION*/
    int num;
    for (int i = 0; i < maxSize; i++){
        if (scanf("%d", &num) == 1){
            array[i] = num;
        } else {
            return i;
        }
    }
    return maxSize;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
