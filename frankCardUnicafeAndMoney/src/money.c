#include <stdlib.h>
#include "money.h"

Money money_add(Money first, Money second){
    first.euros += second.euros;
    
    if (first.cents + second.cents >= 100){
        first.cents = (first.cents + second.cents - 100);
        first.euros++;
    } else {
        first.cents += second.cents;
    }
    
    return first;
}

Money money_sub(Money first, Money second){
    if (money_comp(first, second) < 0) {
        return first;
    }
    
    first.euros -= second.euros;
    
    if (second.cents > first.cents) {
        first.cents = first.cents+100-second.cents;
        first.euros--;
    } else {
        first.cents = first.cents-second.cents;
    }
    
    return first;
}

int money_comp(Money first, Money second){
    if (first.euros != second.euros){
        if (first.euros > second.euros){
            return 1;
        } else {
            return -1;
        }
    } else if (first.cents > second.cents){
        return 1;
    } else if (first.cents < second.cents){
        return -1;
    }
    return 0;
}
