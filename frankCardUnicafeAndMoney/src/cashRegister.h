#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

CashRegister* newCashRegister(char* name);
char* getCashRegisterName(CashRegister* cashRegister);
Money* getCashInRegister(CashRegister* cashRegister);
int getEconomicalSold(CashRegister* cashRegister);
int getGourmetSold(CashRegister* cashRegister);
Money* payEconomical(CashRegister* cashRegister, Money* cashGiven);
Money* payGourmet(CashRegister* cashRegister, Money* cashGiven);
int payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card);
int payGourmetFromCard(CashRegister* cashRegister, FrankCard* card);
void loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, Money* amount);
void cashRegisterFree(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

