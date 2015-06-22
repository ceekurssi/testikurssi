#include <stdio.h>
#include <math.h>
#include "source.h"


/*BEGIN SOLUTION*/
void printTree(int height){
    for (int i = 1; i <= height; i++){
        printWhitespaces(height-i);
        printStars(i+(i-1));
    }
    printWhitespaces(height-2);
    printStars(3);
    printWhitespaces(height-2);
    printStars(3);
}

void printWhitespaces(int size){
    for (int i = 0; i < size; i++){
        printf(" ");
    }
}

void printStars(int size){
    for (int i = 0; i < size; i++){
        printf("*");
    }
    printf("\n");
}
/*END SOLUTION*/
