#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"

int main() {
    CashRegister* unicafeExactum = newCashRegister("Unicafe Exactum");
    FrankCard* cardKalle = newFrankCard("Kalle's card");
    loadMoneyToCard(unicafeExactum, cardKalle, 2.0);
    printf("%s: balance is %.2f\n", getCardName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %.2f\n", getCashRegisterName(unicafeExactum), getCashInRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (payGourmetFromCard(unicafeExactum, cardKalle)){
        printf("true\n");
    } else {
        printf("false\n"); /*payment success: false*/
    }
    printf("%s: balance is %.2f\n", getCardName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    loadMoneyToCard(unicafeExactum, cardKalle, 200.0);
    printf("%s: balance is %.2f\n", getCardName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    payEconomicalFromCard(unicafeExactum, cardKalle);
    printf("%s: balance is %.2f\n", getCardName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %.2f\n", getCashRegisterName(unicafeExactum), getCashInRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1202.00*/
    return 0;
}
