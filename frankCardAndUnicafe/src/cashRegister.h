#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

CashRegister* newCashRegister(char* name);
char* getCashRegisterName(CashRegister* cashRegister);
double getCashInRegister(CashRegister* cashRegister);
int getEconomicalSold(CashRegister* cashRegister);
int getGourmetSold(CashRegister* cashRegister);
double payEconomical(CashRegister* cashRegister, double cashGiven);
double payGourmet(CashRegister* cashRegister, double cashGiven);
int payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card);
int payGourmetFromCard(CashRegister* cashRegister, FrankCard* card);
void loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount);
void cashRegisterFree(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

