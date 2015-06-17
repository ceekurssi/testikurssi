#include <stdio.h>

void multiply_matrix(int size){
    
    /*BEGIN SOLUTION*/
    int i;
    int j;
    
    for (i = 1; i <= size; i++){
        for (j = 1; j <= size; j++){
            printf("%d\t", i*j);
        }
        printf("\n");
    }
    /*END SOLUTION*/
}
