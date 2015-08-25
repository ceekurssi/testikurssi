#include <stdio.h>
#include "source.h"

int merge_doubles() {
    FILE* in1File;
    FILE* in2File;
    FILE* outFile;
    double num1, num2;

    if ((in1File = fopen("in1.txt", "r")) == NULL) {
        printf("a");
        return -1;
    }
    if ((in2File = fopen("in2.txt", "r")) == NULL) {
        printf("b");
        return -1;
    }
    if ((outFile = fopen("out.txt", "w")) == NULL) {
        printf("c");
        return -1;
    }
    if (fscanf(in1File, "%lf", &num1) != 1) {
        printf("d");
        return -1;
    }
    if (fscanf(in2File, "%lf", &num2) != 1) {
        printf("e");
        return -1;
    }
    while (!feof(in1File) && !feof(in2File)) {
        if (num1 < num2) {
            if (fprintf(outFile, "%f ", num1) < 0) {
                printf("f");
                return -1;
            }
            if (fscanf(in1File, "%lf", &num1) != 1) {
                printf("g");
                //return -1;
            }
        } else {
            if (fprintf(outFile, "%f ", num2) < 0) {
                printf("h");
                return -1;
            }
            if (fscanf(in2File, "%lf", &num2) != 1) {
                printf("i");
                //return -1;
            }
        }
    }
    if (!feof(in1File)) {
        while (!feof(in1File)) {
            if (fprintf(outFile, "%f ", num1) < 0) {
                printf("j");
                return -1;
            }
            if (fscanf(in1File, "%lf", &num1) != 1) {
                printf("k");
                //return -1;
            }
        }
    } else if (!feof(in2File)) {
        while (!feof(in2File)) {
            if (fprintf(outFile, "%f ", num2) < 0) {
                printf("l");
                return -1;
            }
            if (fscanf(in2File, "%lf", &num2) != 1) {
                printf("m");
                //return -1;
            }
        }
    }
    if (fclose(in1File) == EOF) {
        printf("n");
        return -1;
    }
    if (fclose(in2File) == EOF) {
        printf("o");
        return -1;
    }
    if (fclose(outFile) == EOF) {
        printf("p");
        return -1;
    }
    return 0;
}
