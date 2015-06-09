#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

typedef struct CashRegister CashRegister;

CashRegister* CashRegister_new(char* name);
char* CashRegister_getName(CashRegister* cashRegister);
double CashRegister_getCashInRegister(CashRegister* cashRegister);
int CashRegister_getEconomicalSold(CashRegister* cashRegister);
int CashRegister_getGourmetSold(CashRegister* cashRegister);
double CashRegister_payEconomical(CashRegister* cashRegister, double cashGiven);
double CashRegister_payGourmet(CashRegister* cashRegister, double cashGiven);
int CashRegister_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card);
int CashRegister_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card);
void CashRegister_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount);
void CashRegister_free(CashRegister* cashRegister);


#endif	/* CASHREGISTER_H */

