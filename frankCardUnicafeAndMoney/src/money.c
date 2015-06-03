#include <stdlib.h>
#include "money.h"

struct Money{
    int euros;
    int cents;
};

Money* newMoney(int euros, int cents){
    Money* money;
    money = malloc(sizeof(Money));
    
    if (money == NULL){
        return NULL;
    }
    
    money->euros = euros;
    money->cents = cents;
    return money;
}

int getEuros(Money* money){
    return money->euros;
}

int getCents(Money* money){
    return money->cents;
}

Money* plus(Money* first, Money* second){
    int newCents = 0;
    int newEuros = 0;
    
    if (first->cents + second->cents >= 100){
        newCents += (first->cents + second->cents - 100);
        newEuros += 1;
    } else {
        newCents += (first->cents + second->cents);
    }
    newEuros += first->euros;
    newEuros += second->euros;
    
    Money* money = newMoney(newEuros, newCents);
    return money;
}

int less(Money* first, Money* second){
    if (first->euros != second->euros){
        if (first->euros > second->euros){
            return 1;
        } else {
            return -1;
        }
    } else if (first->cents > second->cents){
        return 1;
    } else if (first->cents < second->cents){
        return -1;
    }
    return 0;
}

Money* minus(Money* first, Money* second){
    int newCents = 0;
    int newEuros = 0;
    
    if (first->cents < second->cents && (first->euros-1) >= second->euros){
        newCents += (100 + first->cents - second->cents);
        newEuros += (first->euros -1 - second->euros);
    } else if (first->cents >= second->cents && (first->euros-1) >= second->euros){
        newCents += (first->cents - second->cents);
        newEuros += (first->euros - second->euros);
    }
    Money* money = newMoney(newEuros, newCents);
    return money;
}

void moneyFree(Money* money){
    free(money);
    return;
}

