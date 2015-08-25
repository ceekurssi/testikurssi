#include <stdio.h>
#include "source.h"

/* Tää on vielä kesken
 * Write a function int merge_doubles, that merges two files, in1.txt and in2.txt, containing sorted lists of double values 
 * into output file, out.txt, that also should contain a sorted list.
 * For example given the following two input files:
 * 1.1 3.5 8
 * 2.3 4.1 9.3
 * the output file should contain:
 * 1.1 2.3 3.5 4.1 8 9.3
 * Function should return 0, if successful and -1 if there was an error. */

int main() {
    int ret = merge_doubles();
    printf("%d\n", ret);
    return 0;
}
