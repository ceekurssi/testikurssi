#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int line_count(char *filename) {
    /*BEGIN SOLUTION*/
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }
    char buffer[1024];
    int lines = 0;
    
    // use fgets to read individual lines, and count them
    while (!feof(file)) {
        buffer[0] = 0;
        fgets(buffer, sizeof(buffer), file);
        // EOF causes buffer to have length 0 (fgets contains '\n')
        // Note that feof will be set only after trying to read past end of file
        if (strlen(buffer) > 0) {
            lines++;
        }
    }
    fclose(file);
    return lines;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
