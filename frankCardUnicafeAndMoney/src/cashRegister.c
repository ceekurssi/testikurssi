#include <stdlib.h>
#include "cashRegister.h"

struct FrankCard;

struct CashRegister {
    char* name;
    Money cashInRegister;
    int economicalSold;
    int gourmetSold;
};

CashRegister* CashRegister_new(char* name){
    CashRegister* cashRegister;
    
    cashRegister = malloc(sizeof(CashRegister));
    
    if (cashRegister == NULL){
        return NULL;
    }
    
    cashRegister->name = name;
    cashRegister->cashInRegister = (Money){0, 0};
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* CashRegister_getCashRegisterName(CashRegister* cashRegister){
    return cashRegister->name;
}

Money CashRegister_getCashInRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int CashRegister_getEconomicalSold(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int CashRegister_getGourmetSold(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

Money CashRegister_payEconomical(CashRegister* cashRegister, Money cashGiven){
    if (money_comp(cashGiven, PRICE_ECONOMICAL) != -1){
        cashRegister->cashInRegister = money_add(cashRegister->cashInRegister, PRICE_ECONOMICAL);
        cashRegister->economicalSold += 1;
        return money_sub(cashGiven, PRICE_ECONOMICAL);
    } else {
        return cashGiven;
    }
}

Money CashRegister_payGourmet(CashRegister* cashRegister, Money cashGiven){
    if (money_comp(cashGiven, PRICE_GOURMET) != -1){
        cashRegister->cashInRegister = money_add(cashRegister->cashInRegister, PRICE_GOURMET);
        cashRegister->gourmetSold += 1;
        return money_sub(cashGiven, PRICE_GOURMET);
    } else {
        return cashGiven;
    }
}

int CashRegister_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card){
    if (money_comp(FrankCard_getBalance(card), PRICE_ECONOMICAL) != -1){
        FrankCard_pay(card, PRICE_ECONOMICAL);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int CashRegister_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card){
    if (money_comp(FrankCard_getBalance(card), PRICE_GOURMET) != -1){
        FrankCard_pay(card, PRICE_GOURMET);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void CashRegister_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, Money amount){
    FrankCard_loadMoney(card, amount);
    cashRegister->cashInRegister = money_add(amount, cashRegister->cashInRegister);
}

void CashRegister_free(CashRegister* cashRegister){
    free(cashRegister);
    return;
}
