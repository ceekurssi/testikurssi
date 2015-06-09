#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"
#include "money.h"

//tehtävä kesken, testit puuttuu/rikki, mainissa ihan mitä sattuu

int main() {
    Money a = {3, 30};
    Money b = {2, 50};
    Money c = money_sub(a, b);
    
    printf("%d,%02d\n", c.euros, c.cents);
    CashRegister* unicafeExactum = CashRegister_new("Unicafe Exactum");
    FrankCard* cardKalle = FrankCard_new("Kalle's card");
    printf("%s: balance is %d,%02d\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle).euros, FrankCard_getBalance(cardKalle).cents); /*Kalle's card: balance is 2.00*/

    printf("Edullinen lounas maksaa %d,%d\n", PRICE_ECONOMICAL.euros, PRICE_ECONOMICAL.cents);
    printf("Kallis lounas maksaa %d,%d\n", PRICE_GOURMET.euros, PRICE_GOURMET.cents);

    
    CashRegister_loadMoneyToCard(unicafeExactum, cardKalle, (Money){2, 0});
    printf("%s: balance is %d,%02d\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle).euros, FrankCard_getBalance(cardKalle).cents); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %d,%02d\n", CashRegister_getCashRegisterName(unicafeExactum), CashRegister_getCashInRegister(unicafeExactum).euros, CashRegister_getCashInRegister(unicafeExactum).cents); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (CashRegister_payGourmetFromCard(unicafeExactum, cardKalle)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("%s: balance is %d,%02d\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle).euros, FrankCard_getBalance(cardKalle).cents); /*Kalle's card: balance is 2.00*/
    CashRegister_loadMoneyToCard(unicafeExactum, cardKalle, (Money){200, 0});
    printf("%s: balance is %d,%02d\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle).euros, FrankCard_getBalance(cardKalle).cents); /*Kalle's card: balance is 150.00*/
    CashRegister_payEconomicalFromCard(unicafeExactum, cardKalle);
    printf("%s: balance is %d,%02d\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle).euros, FrankCard_getBalance(cardKalle).cents); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %d,%02d\n", CashRegister_getCashRegisterName(unicafeExactum), CashRegister_getCashInRegister(unicafeExactum).euros, CashRegister_getCashInRegister(unicafeExactum).cents); /*Unicafe Exactum: balance is 1202.00*/
    //moneyFree(a);
    //moneyFree(b);
    //moneyFree(c);
    CashRegister_free(unicafeExactum);
    FrankCard_free(cardKalle);
    return 0;
}
