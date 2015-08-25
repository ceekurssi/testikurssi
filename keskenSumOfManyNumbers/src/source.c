#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "source.h"

/*Read numbers from the user and print their sum when user enters 0.*/

void sum_of_many_numbers(void){
    
    /*BEGIN SOLUTION*/
    int number;
    int sum = 0;
    
    while(1){
        //printf("Give a number: ");
        
        if (scanf("%d", &number) != 1 || number == 0){
            break;
        } else {
            sum += number;
        }
        
    }
        
    printf("%d\n", sum);
    /*END SOLUTION*/
}
