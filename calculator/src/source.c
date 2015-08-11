#include <stdio.h>
#include "source.h"

void calculate(void) {

    /*BEGIN SOLUTION*/
    float a, b;
    char operator;
    int i;
    float ans;

    i = scanf("%f %c %f", &a, &operator, &b);
    if (i != 3) {
        printf("error\n");
    } else {
        if (operator == '+') {
            ans = a + b;
            printf("%.2f %c %.2f = %.2f\n", a, operator, b, ans);
        } else if (operator == '-') {
            ans = a - b;
            printf("%.2f %c %.2f = %.2f\n", a, operator, b, ans);
        } else if (operator == '*') {
            ans = a * b;
            printf("%.2f %c %.2f = %.2f\n", a, operator, b, ans);
        } else if (operator == '/') {
            ans = a / b;
            printf("%.2f %c %.2f = %.2f\n", a, operator, b, ans);
        } else {
            printf("error\n");
        }
    }
    /*END SOLUTION*/
}
