#include "source.h"

int binary_to_decimal(int binary) {
    
    /*BEGIN SOLUTION*/
    int digit;
    int decimal = 0;
    int value = 1;

    while (binary > 0){
        digit = binary % 10;
        decimal += (value * digit);
        value *= 2;
        binary /= 10;
    }
  return decimal;
  /*END SOLUTION*/
}
