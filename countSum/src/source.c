#include <stdio.h>
#include "source.h"

void count_sum(void) {
    
    /*BEGIN SOLUTION*/
    int a, b, sum;
    scanf("%d", &a);
    scanf("%d", &b);
    
    sum = a + b;
    
    printf("%d + %d = %d\n", a, b, sum);
    /*END SOLUTION*/
}
