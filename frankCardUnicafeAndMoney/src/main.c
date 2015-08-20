#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"
#include "money.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 6.
 * Copy frankCard.c and cashRegister.c from previous exercise. 
 * Implement following functions in money.c.
 * Function money_add should add the second money to the first and then return the first money. 
 * Function money_sub should subtract the second money from the first and then return the first money.
 * Function money_comp should return 1 if the first given money is more than the second, -1 if the first money is less and 0 if they are same.
 * Modify frankCard and cashRegister so that they use Money.
 * k*/

int main(void) {
    Money a = {3, 30};
    Money b = {2, 50};
    Money c = sub_money(a, b);
    
    printf("%d,%02d\n", c.euros, c.cents);
    CashRegister* unicafeExactum = new_CashRegister("Unicafe Exactum");
    FrankCard* cardKalle = new_FrankCard("Kalle's card");
    printf("%s: balance is %d,%02d\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle).euros, getBalance_FrankCard(cardKalle).cents); /*Kalle's card: balance is 2.00*/

    printf("Economical lunch price %d,%d\n", PRICE_ECONOMICAL.euros, PRICE_ECONOMICAL.cents);
    printf("Gourmet lunch price %d,%d\n", PRICE_GOURMET.euros, PRICE_GOURMET.cents);

    
    loadMoneyToCard_CashRegister(unicafeExactum, cardKalle, (Money){2, 0});
    printf("%s: balance is %d,%02d\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle).euros, getBalance_FrankCard(cardKalle).cents); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %d,%02d\n", getCashRegisterName_CashRegister(unicafeExactum), getCashInRegister_CashRegister(unicafeExactum).euros, getCashInRegister_CashRegister(unicafeExactum).cents); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (payGourmetFromCard_CashRegister(unicafeExactum, cardKalle)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("%s: balance is %d,%02d\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle).euros, getBalance_FrankCard(cardKalle).cents); /*Kalle's card: balance is 2.00*/
    loadMoneyToCard_CashRegister(unicafeExactum, cardKalle, (Money){200, 0});
    printf("%s: balance is %d,%02d\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle).euros, getBalance_FrankCard(cardKalle).cents); /*Kalle's card: balance is 150.00*/
    payEconomicalFromCard_CashRegister(unicafeExactum, cardKalle);
    printf("%s: balance is %d,%02d\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle).euros, getBalance_FrankCard(cardKalle).cents); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %d,%02d\n", getCashRegisterName_CashRegister(unicafeExactum), getCashInRegister_CashRegister(unicafeExactum).euros, getCashInRegister_CashRegister(unicafeExactum).cents); /*Unicafe Exactum: balance is 1202.00*/
    free_CashRegister(unicafeExactum);
    free_FrankCard(cardKalle);
    return 0;
}
