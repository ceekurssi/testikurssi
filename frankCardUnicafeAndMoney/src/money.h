#ifndef MONEY_H
#define	MONEY_H

typedef struct Money Money;

Money* newMoney(int euros, int cents);
int getEuros(Money* money);
int getCents(Money* money);
Money* plus(Money* first, Money* second);
int less(Money* first, Money* second);
Money* minus(Money* first, Money* second);
void moneyFree(Money* money);

#endif	/* MONEY_H */

