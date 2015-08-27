#include <stdio.h>
#include <ctype.h>
#include "source.h"

void print_capsLock(){
    /*BEGIN SOLUTION*/
    char word[10];
    
    for (int i = 0; i < 10; i++){
        scanf("%c", &word[i]);
    }
    
    for (int i = 0; i < 10; i++){
        printf("%c", toupper(word[i]));
    }
    printf("\n");
    /*END SOLUTION*/
}
