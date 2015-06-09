#include <stdlib.h>
/*BEGIN SOLUTION*/
#include "frankCard.h"

struct FrankCard {
    char* name;
    Money balance;
};

FrankCard* FrankCard_new(char* name) {
    FrankCard* card;

    card = malloc(sizeof (FrankCard));
    if (card == NULL) {
        return NULL;
    }
    card->name = name;
    card->balance = (Money){0, 0};
    return card;
}

char* FrankCard_getCardName(FrankCard* card) {
    return card->name;
}

Money FrankCard_getBalance(FrankCard* card) {
    return card->balance;
}

void FrankCard_loadMoney(FrankCard* card, Money amount) {
    card->balance = money_add(card->balance, amount);
}

int FrankCard_pay(FrankCard* card, Money amount) {
    if (money_comp(card->balance, amount) == -1) {
        return 0;
    } else {
        card->balance = money_sub(card->balance, amount);
        return 1;
    }
}

void FrankCard_free(FrankCard* card) {
    free(card);
    return;
}
/*END SOLUTION*/
