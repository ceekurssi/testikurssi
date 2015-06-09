#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

static const Money PRICE_ECONOMICAL = {2, 60};
static const Money PRICE_GOURMET = {4, 40};

CashRegister* CashRegister_new(char* name);
char* CashRegister_getCashRegisterName(CashRegister* cashRegister);
Money CashRegister_getCashInRegister(CashRegister* cashRegister);
int CashRegister_getEconomicalSold(CashRegister* cashRegister);
int CashRegister_getGourmetSold(CashRegister* cashRegister);
Money CashRegister_payEconomical(CashRegister* cashRegister, Money cashGiven);
Money CashRegister_payGourmet(CashRegister* cashRegister, Money cashGiven);
int CashRegister_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card);
int CashRegister_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card);
void CashRegister_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, Money amount);
void CashRegister_free(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

