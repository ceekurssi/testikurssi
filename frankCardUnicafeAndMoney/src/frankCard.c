#include <stdlib.h>
/*BEGIN SOLUTION*/
#include "frankCard.h"

struct FrankCard {
    char* name;
    Money* balance;
};

FrankCard* newFrankCard(char* name){
    FrankCard* card;
    
    card = malloc(sizeof(FrankCard));
    if (card == NULL){
        return NULL;
    }
    card->name = name;
    card->balance = newMoney(0,0);
    return card;
}
char* getCardName(FrankCard* card){
    return card->name;
}
Money* getBalance(FrankCard* card){
    return card->balance;
}

void loadMoney(FrankCard* card, Money* amount){
    if (amount != NULL){
        card->balance = plus(card->balance, amount);
    }
    if (less(card->balance, newMoney(150, 0)) == 1){
        card->balance = newMoney(150, 0);
    }
}

int pay(FrankCard* card, Money* amount){
    if (less(card->balance, amount) == -1){
        return 0;
    } else {
        card->balance = minus(card->balance, amount);
        return 1;
    }
}

void frankCardFree(FrankCard* card){
    moneyFree(card->balance);
    free(card);
    return;
}
/*END SOLUTION*/
