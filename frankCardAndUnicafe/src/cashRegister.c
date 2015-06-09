#include <stdlib.h>
#include "cashRegister.h"

struct CashRegister {
    char* name;
    double cashInRegister;
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
    cashRegister->cashInRegister = 1000.0;
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* CashRegister_getName(CashRegister* cashRegister){
    return cashRegister->name;
}

double CashRegister_getCashInRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int CashRegister_getEconomicalSold(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int CashRegister_getGourmetSold(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

double CashRegister_payEconomical(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 2.60){
        cashRegister->cashInRegister += 2.60;
        cashRegister->economicalSold += 1;
        return cashGiven - 2.60;
    } else {
        return cashGiven;
    }
}

double CashRegister_payGourmet(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 4.40){
        cashRegister->cashInRegister += 4.40;
        cashRegister->gourmetSold += 1;
        return cashGiven -4.40;
    } else {
        return cashGiven;
    }
}

int CashRegister_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card){
    if (FrankCard_getBalance(card) >= 2.60){
        FrankCard_pay(card, 2.60);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int CashRegister_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card){
    if (FrankCard_getBalance(card) >= 4.40){
        FrankCard_pay(card, 4.40);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void CashRegister_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount){
    FrankCard_loadMoney(card, amount);
    cashRegister->cashInRegister += amount;
}

void CashRegister_free(CashRegister* cashRegister){
    free(cashRegister);
    return;
}
