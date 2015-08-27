#include "source.h"
#include <stdio.h>

int replace_blanks() {
    /*BEGIN SOLUTION*/
    FILE* inOutFile;
    FILE* tempFile;
    int c;
    if ((inOutFile = fopen("textfile.txt", "r")) == NULL) {
        return -1;
    }
    if ((tempFile = tmpfile()) == NULL) {
        return -1;
    }

    while ((c = fgetc(inOutFile)) != EOF) {
        if (c != ' ') {
            fputc(c, tempFile);
        } else {
            fputc('*', tempFile);
        }
    }
    if (fclose(inOutFile) == EOF) {
        return -1;
    }
    if ((inOutFile = fopen("textfile.txt", "w")) == NULL){
        return -1;
    }
    rewind(tempFile);
    while((c = fgetc(tempFile)) != EOF){
        fputc(c, inOutFile);
    }
    if (fclose(inOutFile) == EOF){
        return -1;
    }
    
    return 0;
    /*END SOLUTION*/
    /*STUB: return -1;*/
}
