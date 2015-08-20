#include <stdlib.h>
#include "frankCard.h"

FrankCard* new_FrankCard(char* name){
    /*BEGIN SOLUTION*/
    FrankCard* card;
    
    card = malloc(sizeof(FrankCard));
    if (card == NULL){
        return NULL;
    }
    card->name = name;
    card->balance = 0.0;
    return card;
    /*END SOLUTION*/
    return NULL;
}
char* getName_FrankCard(FrankCard* card){
    return card->name;
}
double getBalance_FrankCard(FrankCard* card){
    return card->balance;
}

void loadMoney_FrankCard(FrankCard* card, double amount){
    /*BEGIN SOLUTION*/
    if (amount > 0){
        card->balance += amount;
    }
    if (card->balance > 150){
        card->balance = 150.0;
    }
    /*END SOLUTION*/
}

void payEconomical_FrankCard(FrankCard* card){
    /*BEGIN SOLUTION*/
    if (card->balance >= 2.60){
        card->balance -= 2.60;
    }
    /*END SOLUTION*/
}

void payGourmet_FrankCard(FrankCard* card){
    /*BEGIN SOLUTION*/
    if (card->balance >= 4.40){
        card->balance -= 4.40;
    }
    /*END SOLUTION*/
}

int free_FrankCard(FrankCard* card){
    /*BEGIN SOLUTION*/
    free(card);
    return 1;
    /*END SOLUTION*/
    /*STUB: RETURN -1; */
}
