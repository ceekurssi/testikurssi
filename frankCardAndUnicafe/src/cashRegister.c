/*BEGIN SOLUTION*/
#include <stdlib.h>
#include "cashRegister.h"

struct CashRegister {
    char* name;
    double cashInRegister;
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
    cashRegister->cashInRegister = 1000.0;
    cashRegister->economicalSold = 0;
    cashRegister->gourmetSold = 0;
    return cashRegister;
}

char* getName_CashRegister(CashRegister* cashRegister){
    return cashRegister->name;
}

double getCashInRegister_CashRegister(CashRegister* cashRegister){
    return cashRegister->cashInRegister;
}

int getEconomicalSold_CashRegister(CashRegister* cashRegister){
    return cashRegister->economicalSold;
}

int getGourmetSold_CashRegister(CashRegister* cashRegister){
    return cashRegister->gourmetSold;
}

double payEconomical_CashRegister(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 2.60){
        cashRegister->cashInRegister += 2.60;
        cashRegister->economicalSold += 1;
        return cashGiven - 2.60;
    } else {
        return cashGiven;
    }
}

double payGourmet_CashRegister(CashRegister* cashRegister, double cashGiven){
    if (cashGiven >= 4.40){
        cashRegister->cashInRegister += 4.40;
        cashRegister->gourmetSold += 1;
        return cashGiven -4.40;
    } else {
        return cashGiven;
    }
}

int payEconomicalFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    if (getBalance_FrankCard(card) >= 2.60){
        pay_FrankCard(card, 2.60);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
}

int payGourmetFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    if (getBalance_FrankCard(card) >= 4.40){
        pay_FrankCard(card, 4.40);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
}

void loadMoneyToCard_CashRegister(CashRegister* cashRegister, FrankCard* card, double amount){
    loadMoney_FrankCard(card, amount);
    cashRegister->cashInRegister += amount;
}

void free_CashRegister(CashRegister* cashRegister){
    free(cashRegister);
    return;
}
/*END SOLUTION*/
