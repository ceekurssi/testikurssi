#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;

/*BEGIN SOLUTION*/
struct FrankCard {
    char* name;
    double balance;
};

FrankCard* new_FrankCard(char* name);
char* getName_FrankCard(FrankCard* card);
double getBalance_FrankCard(FrankCard* card);
void loadMoney_FrankCard(FrankCard* card, double amount);
void payEconomical_FrankCard(FrankCard* card);
void payGourmet_FrankCard(FrankCard* card);
int free_FrankCard(FrankCard* card);

/*END SOLUTION*/

#endif	/* FRANKCARD_H */

