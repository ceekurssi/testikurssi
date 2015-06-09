#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"

int main() {
    CashRegister* unicafeExactum = CashRegister_new("Unicafe Exactum");
    FrankCard* cardKalle = FrankCard_new("Kalle's card");
    CashRegister_loadMoneyToCard(unicafeExactum, cardKalle, 2.0);
    printf("%s: balance is %.2f\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %.2f\n", CashRegister_getName(unicafeExactum), CashRegister_getCashInRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (CashRegister_payGourmetFromCard(unicafeExactum, cardKalle)){
        printf("true\n");
    } else {
        printf("false\n"); /*payment success: false*/
    }
    printf("%s: balance is %.2f\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    CashRegister_loadMoneyToCard(unicafeExactum, cardKalle, 200.0);
    printf("%s: balance is %.2f\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    CashRegister_payEconomicalFromCard(unicafeExactum, cardKalle);
    printf("%s: balance is %.2f\n", FrankCard_getCardName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %.2f\n", CashRegister_getName(unicafeExactum), CashRegister_getCashInRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1202.00*/
    FrankCard_free(cardKalle);
    CashRegister_free(unicafeExactum);
    return 0;
}
