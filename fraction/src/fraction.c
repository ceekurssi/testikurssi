/*BEGIN SOLUTION*/
#include <stdio.h>
#include <stdlib.h>
/*END SOLUTION*/
#include "fraction.h"

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
};

unsigned int gcd(unsigned int u, unsigned int v);

unsigned int Fraction_getNumerator(Fraction* f){
    return f->numerator;
}

unsigned int Fraction_getDenominator(Fraction* f){
    return f->denominator;
}

Fraction* Fraction_new(unsigned int numerator, unsigned int denominator){
    /*BEGIN SOLUTION*/
    Fraction* newFraction = malloc(sizeof(Fraction));
    newFraction->numerator = numerator;
    newFraction->denominator = denominator;
    return newFraction;
    /*END SOLUTION*/
    /* STUB: return NULL; */
}

void Fraction_free(Fraction* f){
    /*BEGIN SOLUTION*/
    free(f);
    /*END SOLUTION*/
}

int Fraction_compare(const Fraction* first, const Fraction* second){
    /*BEGIN SOLUTION*/
    int a = first->numerator * second->denominator;
    int b = first->denominator * second->numerator;
    
    if (a < b){
        return -1;
    } else if (a == b){
        return 0;
    } else {
        return 1;
    }
    /*END SOLUTION*/
    /*STUB: return NULL;*/
}

void Fraction_print(const Fraction* f){
    printf("%d / %d\n", f->numerator, f->denominator);
}


/* Algorithm for determining greatest common divisor */
/* The function returns gcd between the two parameters, u and v */
/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}

void Fraction_reduce(Fraction* f){
    /*BEGIN SOLUTION*/
    unsigned int divisor = gcd(f->numerator, f->denominator);
    f->numerator /= divisor;
    f->denominator /= divisor;
    /*END SOLUTION*/
}

/*BEGIN SOLUTION*/
void Fraction_expand(Fraction* first, Fraction* second){
    if (first->denominator != second->denominator){
        unsigned int n = first->denominator;
        first->numerator *= second->denominator;
        first->denominator *= second->denominator;
        second->numerator *= n;
        second->denominator *= n;
    }
}
/*END SOLUTION*/

Fraction* Fraction_add(const Fraction* first, const Fraction* second){
    /*BEGIN SOLUTION*/
    Fraction nFirst = *first;
    Fraction nSecond = *second;
    Fraction_expand(&nFirst, &nSecond);
    unsigned int num = nFirst.numerator + nSecond.numerator;
    unsigned int den = nFirst.denominator;
    Fraction* result = Fraction_new(num, den);
    Fraction_reduce(result);
    return result;
    /*END SOLUTION*/
    /*STUB: return NULL; */
}

Fraction* Fraction_subtract(const Fraction* first, const Fraction* second){
    /*BEGIN SOLUTION*/
    Fraction nFirst = *first;
    Fraction nSecond = *second;
    Fraction_expand(&nFirst, &nSecond);
    unsigned int num = nFirst.numerator - nSecond.numerator;
    unsigned int den = nFirst.denominator;
    Fraction* result = Fraction_new(num, den);
    Fraction_reduce(result);
    return result;
    /*END SOLUTION*/
    /*STUB: return NULL; */
}

Fraction* Fraction_multiply(const Fraction* first, const Fraction* second){
    /*BEGIN SOLUTION*/
    unsigned int num = first->numerator * second->numerator;
    unsigned int den = first->denominator * second->denominator;
    Fraction* result = Fraction_new(num, den);
    Fraction_reduce(result);
    return result;
    /*END SOLUTION*/
    /*STUB: return NULL; */
}

Fraction* Fraction_divide(const Fraction* first, const Fraction* second){
    /*BEGIN SOLUTION*/
    unsigned int num = first->numerator * second->denominator;
    unsigned int den = first->denominator * second->numerator;
    Fraction* result = Fraction_new(num, den);
    Fraction_reduce(result);
    return result;
    /*END SOLUTION*/
    /*STUB: return NULL; */
}
