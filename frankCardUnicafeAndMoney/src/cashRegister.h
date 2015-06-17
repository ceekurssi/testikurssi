#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

static const Money PRICE_ECONOMICAL = {2, 60};
static const Money PRICE_GOURMET = {4, 40};

CashRegister* new_CashRegister(char* name);
char* getCashRegisterName_CashRegister(CashRegister* cashRegister);
Money getCashInRegister_CashRegister(CashRegister* cashRegister);
int getEconomicalSold_CashRegister(CashRegister* cashRegister);
int getGourmetSold_CashRegister(CashRegister* cashRegister);
Money payEconomical_CashRegister(CashRegister* cashRegister, Money cashGiven);
Money payGourmet_CashRegister(CashRegister* cashRegister, Money cashGiven);
int payEconomicalFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card);
int payGourmetFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card);
void loadMoneyToCard_CashRegister(CashRegister* cashRegister, FrankCard* card, Money amount);
void free_CashRegister(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

