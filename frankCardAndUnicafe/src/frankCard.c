#include <stdlib.h>
/*BEGIN SOLUTION*/
#include "frankCard.h"

struct FrankCard {
    char* name;
    double balance;
};

FrankCard* newFrankCard(char* name){
    FrankCard* card;
    
    card = malloc(sizeof(FrankCard));
    if (card == NULL){
        return NULL;
    }
    card->name = name;
    card->balance = 0.0;
    return card;
}
char* getCardName(FrankCard* card){
    return card->name;
}
double getBalance(FrankCard* card){
    return card->balance;
}

void loadMoney(FrankCard* card, double amount){
    if (amount > 0){
        card->balance += amount;
    }
    if (card->balance > 150){
        card->balance = 150.0;
    }
}

int pay(FrankCard* card, double amount){
    if (card->balance < amount){
        return 0;
    } else {
        card->balance -= amount;
        return 1;
    }
}

void frankCardFree(FrankCard* card){
    free(card);
    return;
}
/*END SOLUTION*/
