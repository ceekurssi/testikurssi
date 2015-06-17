#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

FrankCard* new_FrankCard(char* name);
char* getName_FrankCard(FrankCard* card);
double getBalance_FrankCard(FrankCard* card);
void loadMoney_FrankCard(FrankCard* card, double amount);
void payEconomical_FrankCard(FrankCard* card);
void payGourmet_FrankCard(FrankCard* card);
void free_FrankCard(FrankCard* card);

#endif	/* FRANKCARD_H */

