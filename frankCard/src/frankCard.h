#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

FrankCard* newFrankCard(char* name);
char* getName(FrankCard* card);
double getBalance(FrankCard* card);
void loadMoney(FrankCard* card, double amount);
void payEconomical(FrankCard* card);
void payGourmet(FrankCard* card);
void frankCardFree(FrankCard* card);

#endif	/* FRANKCARD_H */

