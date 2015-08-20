#include <stdlib.h>
#include "frankCard.h"

/*BEGIN SOLUTION*/

FrankCard* new_FrankCard(char* name){
    FrankCard* card;
    
    card = malloc(sizeof(FrankCard));
    if (card == NULL){
        return NULL;
    }
    card->name = name;
    card->balance = 0.0;
    return card;
}
char* getName_FrankCard(FrankCard* card){
    return card->name;
}
double getBalance_FrankCard(FrankCard* card){
    return card->balance;
}

void loadMoney_FrankCard(FrankCard* card, double amount){
    if (amount > 0){
        card->balance += amount;
    }
    if (card->balance > 150){
        card->balance = 150.0;
    }
}

void payEconomical_FrankCard(FrankCard* card){
    if (card->balance >= 2.60){
        card->balance -= 2.60;
    }
}

void payGourmet_FrankCard(FrankCard* card){
    if (card->balance >= 4.40){
        card->balance -= 4.40;
    }
}

int free_FrankCard(FrankCard* card){
    free(card);
    return 1;
}

/*END SOLUTION*/
