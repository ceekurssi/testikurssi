#include <stdlib.h>
/*BEGIN SOLUTION*/
#include "frankCard.h"

struct FrankCard {
    char* name;
    Money balance;
};

FrankCard* new_FrankCard(char* name) {
    FrankCard* card;

    card = malloc(sizeof (FrankCard));
    if (card == NULL) {
        return NULL;
    }
    card->name = name;
    card->balance = (Money){0, 0};
    return card;
}

char* getCardName_FrankCard(FrankCard* card) {
    return card->name;
}

Money getBalance_FrankCard(FrankCard* card) {
    return card->balance;
}

void loadMoney_FrankCard(FrankCard* card, Money amount) {
    card->balance = add_money(card->balance, amount);
}

int pay_FrankCard(FrankCard* card, Money amount) {
    if (comp_money(card->balance, amount) == -1) {
        return 0;
    } else {
        card->balance = sub_money(card->balance, amount);
        return 1;
    }
}

void free_FrankCard(FrankCard* card) {
    free(card);
    return;
}
/*END SOLUTION*/
