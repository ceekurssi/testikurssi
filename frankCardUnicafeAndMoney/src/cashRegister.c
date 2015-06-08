#include <stdlib.h>
#include "cashRegister.h"

struct FrankCard;

struct CashRegister {
    char* name;
    Money* cashInRegister;
    int economicalSold;
    int gourmetSold;
};

CashRegister* newCashRegister(char* name){
    CashRegister* cashRegister;
    
    cashRegister = malloc(sizeof(CashRegister));
    
    if (cashRegister == NULL){
        return NULL;
    }
    
    cashRegister->name = name;
    cashRegister->cashInRegister = newMoney(1000, 0);
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* getCashRegisterName(CashRegister* cashRegister){
    return cashRegister->name;
}

Money* getCashInRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int getEconomicalSold(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int getGourmetSold(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

Money* payEconomical(CashRegister* cashRegister, Money* cashGiven){
    Money* economical = newMoney(2,60);
    if (less(cashGiven, economical) != -1){
        cashRegister->cashInRegister = plus(cashRegister->cashInRegister, economical);
        cashRegister->economicalSold += 1;
        return minus(cashGiven, economical);
    } else {
        return cashGiven;
    }
}

Money* payGourmet(CashRegister* cashRegister, Money* cashGiven){
    if (less(cashGiven, newMoney(4,40)) != -1){
        cashRegister->cashInRegister = plus(cashRegister->cashInRegister, newMoney(4, 40));
        cashRegister->gourmetSold += 1;
        return minus(cashGiven, newMoney(4, 40));
    } else {
        return cashGiven;
    }
}

int payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card){
    if (less(getBalance(card), newMoney(2, 60)) != -1){
        pay(card, newMoney(2,60));
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int payGourmetFromCard(CashRegister* cashRegister, FrankCard* card){
    if (less(getBalance(card), newMoney(4, 40)) != -1){
        pay(card, newMoney(4,40));
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, Money* amount){
    loadMoney(card, amount);
    cashRegister->cashInRegister = plus(amount, cashRegister->cashInRegister);
}

void cashRegisterFree(CashRegister* cashRegister){
    free(cashRegister->cashInRegister);
    free(cashRegister);
    return;
}
