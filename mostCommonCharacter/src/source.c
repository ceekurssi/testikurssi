#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int most_common_character(char *filename) {
    /*BEGIN SOLUTION*/
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }
    unsigned int counts[128];
    memset(counts, 0, sizeof(counts));
    
    while (!feof(file)) {
        // process in chunks of one kilobyte
        char buffer[1024];
        int n = fread(buffer, 1, sizeof(buffer), file);
        if (ferror(file)) {
            fclose(file);
            return -1;
        }
        // counts array has one element for each character
        // the array contains the number of times a particular character
        // has occurred in file
        for (int i = 0; i < n; i++) {
            if (buffer[i] > 0 && isalpha(buffer[i]))
                counts[(int)buffer[i]]++;
        }
    }
    int maxc = 0;
    // find out which character has the largest count
    for (int i = 1; i < 128; i++) {
        if (counts[i] > counts[maxc])
            maxc = i;
    }
    fclose(file);
    return maxc;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
