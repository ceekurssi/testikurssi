#include <stdlib.h>
#include "cashRegister.h"

struct FrankCard;

struct CashRegister {
    char* name;
    Money cashInRegister;
    int economicalSold;
    int gourmetSold;
};

CashRegister* new_CashRegister(char* name){
    CashRegister* cashRegister;
    
    cashRegister = malloc(sizeof(CashRegister));
    
    if (cashRegister == NULL){
        return NULL;
    }
    
    cashRegister->name = name;
    cashRegister->cashInRegister = (Money){1000, 0};
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* getCashRegisterName_CashRegister(CashRegister* cashRegister){
    return cashRegister->name;
}

Money getCashInRegister_CashRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int getEconomicalSold_CashRegister(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int getGourmetSold_CashRegister(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

Money payEconomical_CashRegister(CashRegister* cashRegister, Money cashGiven){
    if (comp_money(cashGiven, PRICE_ECONOMICAL) != -1){
        cashRegister->cashInRegister = add_money(cashRegister->cashInRegister, PRICE_ECONOMICAL);
        cashRegister->economicalSold += 1;
        return sub_money(cashGiven, PRICE_ECONOMICAL);
    } else {
        return cashGiven;
    }
}

Money payGourmet_CashRegister(CashRegister* cashRegister, Money cashGiven){
    if (comp_money(cashGiven, PRICE_GOURMET) != -1){
        cashRegister->cashInRegister = add_money(cashRegister->cashInRegister, PRICE_GOURMET);
        cashRegister->gourmetSold += 1;
        return sub_money(cashGiven, PRICE_GOURMET);
    } else {
        return cashGiven;
    }
}

int payEconomicalFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    if (comp_money(getBalance_FrankCard(card), PRICE_ECONOMICAL) != -1){
        pay_FrankCard(card, PRICE_ECONOMICAL);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int payGourmetFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    if (comp_money(getBalance_FrankCard(card), PRICE_GOURMET) != -1){
        pay_FrankCard(card, PRICE_GOURMET);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void loadMoneyToCard_CashRegister(CashRegister* cashRegister, FrankCard* card, Money amount){
    loadMoney_FrankCard(card, amount);
    cashRegister->cashInRegister = add_money(cashRegister->cashInRegister, amount);
}

void free_CashRegister(CashRegister* cashRegister){
    free(cashRegister);
    return;
}
