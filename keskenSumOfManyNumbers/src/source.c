#include <stdio.h>
#include <stdlib.h>
#include "source.h"

void sum_of_many_numbers(void){
    
    /*BEGIN SOLUTION*/
    int number;
    int sum = 0;
    
    while(1){
        
        if (scanf("%d", &number) != 1 || number == 0){
            break;
        } else {
            sum += number;
        }
        
    }
        
    printf("%d\n", sum);
    /*END SOLUTION*/
}
