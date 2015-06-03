#ifndef FRANKCARD_H
#define	FRANKCARD_H
#include "money.h"

typedef struct FrankCard FrankCard;

FrankCard* newFrankCard(char* name);
char* getCardName(FrankCard* card);
Money* getBalance(FrankCard* card);
void loadMoney(FrankCard* card, Money* amount);
int pay(FrankCard* card, Money* amount);
void frankCardFree(FrankCard* card);

#endif	/* FRANKCARD_H */

