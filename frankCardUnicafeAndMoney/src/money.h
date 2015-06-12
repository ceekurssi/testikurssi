#ifndef MONEY_H
#define	MONEY_H

typedef struct Money{
    int euros;
    int cents;
} Money;

Money money_add(Money first, Money second);
Money money_sub(Money first, Money second);
int money_comp(Money first, Money second);

#endif	/* MONEY_H */

