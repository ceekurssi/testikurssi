#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

struct Complex {
    int real;
    int imaginary;
};

Complex* Complex_new(int real, int imaginary) {
    /*BEGIN SOLUTION*/
    Complex* newComplex = malloc(sizeof (Complex));
    newComplex->real = real;
    newComplex->imaginary = imaginary;
    return newComplex;
    /*END SOLUTION*/
    /* STUB: return NULL; */
}

void Complex_free(Complex* c) {
    /*BEGIN SOLUTION*/
    free(c);
    /*END SOLUTION*/
}

/*
int Fraction_compare(const Fraction* first, const Fraction* second){

    int a = first->numerator * second->denominator;
    int b = first->denominator * second->numerator;
    
    if (a < b){
        return -1;
    } else if (a == b){
        return 0;
    } else {
        return 1;
    }

}
 */

void Complex_print(const Complex* c) {
    if (c->imaginary >= 0) {
        printf("%d + %di\n", c->real, c->imaginary);
    } else {
        printf("%d %di\n", c->real, c->imaginary);
    }
}

Complex* Complex_add(const Complex* first, const Complex* second) {
    return Complex_new(first->real + second->real, first->imaginary + second->imaginary);
}

Complex* Complex_subtract(const Complex* first, const Complex* second) {
    return Complex_new(first->real - second->real, first->imaginary - second->imaginary);
}

Complex* Complex_multiply(const Complex* first, const Complex* second) {
    return Complex_new(first->real * second->real - first->imaginary * second->imaginary, first->imaginary * second->real + first->real * second->imaginary);
}

Complex* Complex_divide(const Complex* first, const Complex* second) {
    if (second->real != 0 && second->imaginary != 0){
        int temp1 = first->real * second->real + first->imaginary * second->imaginary;
        int temp2 = first->imaginary * second->real - first->real * second->imaginary;
        int temp3 = second->real * second->real + second->imaginary * second->imaginary;
    }
}
