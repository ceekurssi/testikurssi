#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

FrankCard* newFrankCard(char* name);
char* getCardName(FrankCard* card);
double getBalance(FrankCard* card);
void loadMoney(FrankCard* card, double amount);
int pay(FrankCard* card, double amount);
void frankCardFree(FrankCard* card);

#endif	/* FRANKCARD_H */

