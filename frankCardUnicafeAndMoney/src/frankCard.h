#ifndef FRANKCARD_H
#define	FRANKCARD_H
#include "money.h"

typedef struct FrankCard FrankCard;

FrankCard* FrankCard_new(char* name);
char* FrankCard_getCardName(FrankCard* card);
Money FrankCard_getBalance(FrankCard* card);
void FrankCard_loadMoney(FrankCard* card, Money amount);
int FrankCard_pay(FrankCard* card, Money amount);
void FrankCard_free(FrankCard* card);

#endif	/* FRANKCARD_H */

