#include <stdlib.h>
/*BEGIN SOLUTION*/
/*END SOLUTION*/
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
char* getName(FrankCard* card){
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

void payEconomical(FrankCard* card){
    if (card->balance >= 2.60){
        card->balance -= 2.60;
    }
}

void payGourmet(FrankCard* card){
    if (card->balance >= 4.40){
        card->balance -= 4.40;
    }
}

void frankCardFree(FrankCard* card){
    free(card);
    return;
}
