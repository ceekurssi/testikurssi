#include <stdlib.h>
/*BEGIN SOLUTION*/
/*END SOLUTION*/
#include "frankCard.h"

struct FrankCard {
    char* name;
    double balance;
};

FrankCard* FrankCard_new(char* name){
    FrankCard* card;
    
    card = malloc(sizeof(FrankCard));
    if (card == NULL){
        return NULL;
    }
    card->name = name;
    card->balance = 0.0;
    return card;
}
char* FrankCard_getCardName(FrankCard* card){
    return card->name;
}
double FrankCard_getBalance(FrankCard* card){
    return card->balance;
}

void FrankCard_loadMoney(FrankCard* card, double amount){
    if (amount > 0){
        card->balance += amount;
    }
    if (card->balance > 150){
        card->balance = 150.0;
    }
}

int FrankCard_pay(FrankCard* card, double amount){
    if (card->balance < amount){
        return 0;
    } else {
        card->balance -= amount;
        return 1;
    }
}

void FrankCard_free(FrankCard* card){
    free(card);
    return;
}
