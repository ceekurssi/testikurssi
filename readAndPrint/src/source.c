#include <stdlib.h>
#include <stdio.h>
#include "source.h"

void readAndPrint(char* file){
    /*BEGIN SOLUTION*/
    FILE* f = fopen(file, "r");
    int a;
    float b;
    char c;
    if (fscanf(f, "%d %f %c", &a, &b, &c) == 3){
        printf("%d %.2f %c\n", a, b, c);
    }
    fclose(f);
    /*END SOLUTION*/
}
