#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "source.h"

int word_count(char *filename) {
    /*BEGIN SOLUTION*/
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }
    int on_word = 0;
    int count = 0;
    while (!feof(file)) {
        // read in chunks of 1 kilobyte
        char buffer[1024];
        int n = fread(buffer, 1, sizeof(buffer), file);
        if (ferror(file)) {
            fclose(file);
            return -1;
        }
        // check how many words in one chunk
        // use on_word variable to track when we are over space vs. over word
        // when moving to new word (on_word becomes 1), increment word count
        for (int i = 0; i < n; i++) {
            if (!on_word && isalpha(buffer[i])) {
                on_word = 1;
                count++;
            }
            if (isspace(buffer[i]))
                on_word = 0;
        }        
    }
    fclose(file);
    return count;
    /*END SOLUTION*/
    /*STUB: return 0; */
}
