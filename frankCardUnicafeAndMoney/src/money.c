#include <stdlib.h>
#include "money.h"

Money add_money(Money first, Money second){
    /*BEGIN SOLUTION*/
    first.euros += second.euros;
    
    if (first.cents + second.cents >= 100){
        first.cents = (first.cents + second.cents - 100);
        first.euros++;
    } else {
        first.cents += second.cents;
    }
    
    return first;
    /*END SOLUTION*/
}

Money sub_money(Money first, Money second){
    /*BEGIN SOLUTION*/
    if (comp_money(first, second) < 0) {
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
    /*END SOLUTION*/
}

int comp_money(Money first, Money second){
    /*BEGIN SOLUTION*/
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
    /*END SOLUTION*/
}
