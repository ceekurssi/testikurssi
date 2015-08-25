#include <stdio.h>
#include "source.h"

void count_sum(void) {
    
    /*BEGIN SOLUTION*/
    int a, b, sum;
    if (scanf("%d", &a) != 1){
        fprintf(stderr, "error\n");
        return;
    }
    if (scanf("%d", &b) != 1){
        fprintf(stderr, "error\n");
        return;
    }
    
    sum = a + b;
    
    printf("%d + %d = %d\n", a, b, sum);
    /*END SOLUTION*/
}
