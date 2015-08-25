#include <stdio.h>
#include "source.h"

void print(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++){
        printf("arg %d: %s\n", i, argv[i]);
    }
}
