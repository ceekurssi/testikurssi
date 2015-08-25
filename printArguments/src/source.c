#include <stdio.h>
#include "source.h"

void print(int argc, const char* argv[]) {
    /*BEGIN SOLUTION*/
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    /*END SOLUTION*/
}
