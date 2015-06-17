#ifndef MONEY_H
#define	MONEY_H

typedef struct Money{
    int euros;
    int cents;
} Money;

Money add_money(Money first, Money second);
Money sub_money(Money first, Money second);
int comp_money(Money first, Money second);

#endif	/* MONEY_H */

