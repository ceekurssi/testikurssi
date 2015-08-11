#include <stdio.h>
#include "source.h"

void swap(int* a, int* b){
    /*BEGIN SOLUTION*/
    int temp = *a;
    *a = *b;
    *b = temp;
    /*END SOLUTION*/
}
