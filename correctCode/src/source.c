#include "source.h"

int is_prime(int number) {
    
/*STUB:
    int count = 1;
    int i;
    
    for (int i == 2; i <= number/2; i+1){
        if (number % i = 0){
            count+1;
            break;
        }
    }
    
    if (count = 0 & number != 1){
        return 1;
    } else {
        return 0;
    }
*/
    
    /*BEGIN SOLUTION*/
    int count = 0;
    int i;
    
    for (i = 2; i <= number/2; i++){
        if (number % i == 0){
            count++;
            break;
        }
    }
    
    if (count == 0 && number != 1){
        return 1;
    } else {
        return 0;
    }
    /*END SOLUTION*/
}
