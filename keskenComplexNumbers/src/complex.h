#ifndef COMPLEX_H
#define	COMPLEX_H

typedef struct Complex Complex;

Complex* Complex_new(int real, int imaginary);
void Complex_free(Complex* c);
int Complex_compare(const Complex* first, const Complex* second);
void Complex_print(const Complex* c);
Complex* Complex_add(const Complex* first, const Complex* second);
Complex* Complex_subtract(const Complex* first, const Complex* second);
Complex* Complex_multiply(const Complex* first, const Complex* second);
Complex* Complex_divide(const Complex* first, const Complex* second);

#endif	/* COMPLEX_H */

