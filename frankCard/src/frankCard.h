#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

FrankCard* FrankCard_new(char* name);
char* FrankCard_getName(FrankCard* card);
double FrankCard_getBalance(FrankCard* card);
void FrankCard_loadMoney(FrankCard* card, double amount);
void FrankCard_payEconomical(FrankCard* card);
void FrankCard_payGourmet(FrankCard* card);
void FrankCard_free(FrankCard* card);

#endif	/* FRANKCARD_H */

