#include <stdio.h>
#include "source.h"

void printBox(int width, int height) {
    /*BEGIN SOLUTION*/
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("#");
        }
        printf("\n");
    }
    
    /*END SOLUTION*/
}
