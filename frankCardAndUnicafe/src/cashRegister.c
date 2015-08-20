#include <stdlib.h>
#include "cashRegister.h"

/*BEGIN SOLUTION*/
struct CashRegister {
    char* name;
    double cashInRegister;
    int economicalSold;
    int gourmetSold;
};
/*END SOLUTION*/

CashRegister* new_CashRegister(char* name){
    /*BEGIN SOLUTION*/
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
    /*END SOLUTION*/
    /*STUB: return NULL; */
}

char* getName_CashRegister(CashRegister* cashRegister){
    /*BEGIN SOLUTION*/
    return cashRegister->name;
    /*END SOLUTION*/
    /*STUB: return NULL; */
}

double getCashInRegister_CashRegister(CashRegister* cashRegister){
    /*BEGIN SOLUTION*/
    return cashRegister->cashInRegister;
    /*END SOLUTION*/
    /*STUB: return 0.0; */
}

int getEconomicalSold_CashRegister(CashRegister* cashRegister){
    /*BEGIN SOLUTION*/
    return cashRegister->economicalSold;
    /*END SOLUTION*/
    /*STUB: return 0; */
}

int getGourmetSold_CashRegister(CashRegister* cashRegister){
    /*BEGIN SOLUTION*/
    return cashRegister->gourmetSold;
    /*END SOLUTION*/
    /*STUB: return 0; */
}

double payEconomical_CashRegister(CashRegister* cashRegister, double cashGiven){
    /*BEGIN SOLUTION*/
    if (cashGiven >= 2.60){
        cashRegister->cashInRegister += 2.60;
        cashRegister->economicalSold += 1;
        return cashGiven - 2.60;
    } else {
        return cashGiven;
    }
    /*END SOLUTION*/
    /*STUB: return 0.0; */
}

double payGourmet_CashRegister(CashRegister* cashRegister, double cashGiven){
    /*BEGIN SOLUTION*/
    if (cashGiven >= 4.40){
        cashRegister->cashInRegister += 4.40;
        cashRegister->gourmetSold += 1;
        return cashGiven -4.40;
    } else {
        return cashGiven;
    }
    /*END SOLUTION*/
    /*STUB: return 0.0; */
}

int payEconomicalFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    /*BEGIN SOLUTION*/
    if (getBalance_FrankCard(card) >= 2.60){
        payEconomical_FrankCard(card);
        cashRegister->economicalSold += 1;
        return 1;
    } else {
        return 0;
    }
    /*END SOLUTION*/
    /*STUB: return 0; */
}

int payGourmetFromCard_CashRegister(CashRegister* cashRegister, FrankCard* card){
    /*BEGIN SOLUTION*/
    if (getBalance_FrankCard(card) >= 4.40){
        payGourmet_FrankCard(card);
        cashRegister->gourmetSold += 1;
        return 1;
    } else {
        return 0;
    }
    /*END SOLUTION*/
    /*STUB: return 0; */
}

void loadMoneyToCard_CashRegister(CashRegister* cashRegister, FrankCard* card, double amount){
    /*BEGIN SOLUTION*/
    loadMoney_FrankCard(card, amount);
    cashRegister->cashInRegister += amount;
    /*END SOLUTION*/
}

int free_CashRegister(CashRegister* cashRegister){
    /*BEGIN SOLUTION*/
    free(cashRegister);
    return 1;
    /*END SOLUTION*/
    /*STUB: RETURN -1; */
}
