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
char* FrankCard_getName(FrankCard* card){
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

void FrankCard_payEconomical(FrankCard* card){
    if (card->balance >= 2.60){
        card->balance -= 2.60;
    }
}

void FrankCard_payGourmet(FrankCard* card){
    if (card->balance >= 4.40){
        card->balance -= 4.40;
    }
}

void FrankCard_free(FrankCard* card){
    free(card);
    return;
}
