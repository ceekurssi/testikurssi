#include <stdlib.h>
#include "cashRegister.h"

struct FrankCard;

struct CashRegister {
    char* name;
    double cashInRegister;
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
    cashRegister->cashInRegister = 1000.0;
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* getCashRegisterName(CashRegister* cashRegister){
    return cashRegister->name;
}

double getCashInRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int getEconomicalSold(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int getGourmetSold(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

double payEconomical(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 2.60){
        cashRegister->cashInRegister += 2.60;
        cashRegister->economicalSold += 1;
        return cashGiven - 2.60;
    } else {
        return cashGiven;
    }
}

double payGourmet(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 4.40){
        cashRegister->cashInRegister += 4.40;
        cashRegister->gourmetSold += 1;
        return cashGiven -4.40;
    } else {
        return cashGiven;
    }
}

int payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card){
    if (getBalance(card) >= 2.60){
        pay(card, 2.60);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int payGourmetFromCard(CashRegister* cashRegister, FrankCard* card){
    if (getBalance(card) >= 4.40){
        pay(card, 4.40);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount){
    loadMoney(card, amount);
    cashRegister->cashInRegister += amount;
}

void cashRegisterFree(CashRegister* cashRegister){
    free(cashRegister);
    return;
}
