#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

CashRegister* new_CashRegister(char* name);
char* getName_CashRegister(CashRegister* cashRegister);
double getCashInRegister_CashRegister(CashRegister* cashRegister);
int getEconomicalSold_CashRegister(CashRegister* cashRegister);
int getGourmetSold_CashRegister(CashRegister* cashRegister);
double payEconomical_CashRegister(CashRegister* cashRegister, double cashGiven);
double payGourmet_CashRegister(CashRegister* cashRegister, double cashGiven);
int payEconomicalFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card);
int payGourmetFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card);
void loadMoneyToCard_CashRegister(CashRegister* cashRegister, FrankCard* card, double amount);
int free_CashRegister(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

