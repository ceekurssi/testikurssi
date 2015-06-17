#ifndef FRANKCARD_H
#define	FRANKCARD_H
#include "money.h"

typedef struct FrankCard FrankCard;

FrankCard* new_FrankCard(char* name);
char* getCardName_FrankCard(FrankCard* card);
Money getBalance_FrankCard(FrankCard* card);
void loadMoney_FrankCard(FrankCard* card, Money amount);
int pay_FrankCard(FrankCard* card, Money amount);
void free_FrankCard(FrankCard* card);

#endif	/* FRANKCARD_H */

