#include "source.h"

int array_sum(int* array, int size){
    /*BEGIN SOLUTION*/
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += *array++;
    }
    return sum;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
