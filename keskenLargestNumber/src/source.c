#include <stdio.h>
#include <math.h>
#include "source.h"

int maximum_integer(void) {
    int i;
    int maximum = 0;
    
    while(1){
        if (scanf("%d", &i) != 1 || i == 0){
            break;
        }
        if (i > maximum){
            maximum = i;
        }
    }
        
    return maximum;
}
