#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

FrankCard* new_FrankCard(char* name);
char* getCardName_FrankCard(FrankCard* card);
double getBalance_FrankCard(FrankCard* card);
void loadMoney_FrankCard(FrankCard* card, double amount);
int pay_FrankCard(FrankCard* card, double amount);
void free_FrankCard(FrankCard* card);

#endif	/* FRANKCARD_H */

