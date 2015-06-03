#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"
#include "money.h"

int main() {
    Money* a = newMoney(2, 30);
    Money* b = newMoney(2, 50);
    Money* c = minus(a, b);
    printf("%d,%02d\n", getEuros(c), getCents(c));
    CashRegister* unicafeExactum = newCashRegister("Unicafe Exactum");
    FrankCard* cardKalle = newFrankCard("Kalle's card");
    loadMoneyToCard(unicafeExactum, cardKalle, newMoney(2, 0));
    printf("%s: balance is %d,%02d\n", getCardName(cardKalle), getEuros(getBalance(cardKalle)), getCents(getBalance(cardKalle))); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %d,%02d\n", getCashRegisterName(unicafeExactum), getEuros(getCashInRegister(unicafeExactum)), getCents(getCashInRegister(unicafeExactum))); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (payGourmetFromCard(unicafeExactum, cardKalle)){
        printf("true\n");
    } else {
        printf("false\n"); /*payment success: false*/
    }
    printf("%s: balance is %d,%02d\n", getCardName(cardKalle), getEuros(getBalance(cardKalle)), getCents(getBalance(cardKalle))); /*Kalle's card: balance is 2.00*/
    loadMoneyToCard(unicafeExactum, cardKalle, newMoney(200, 0));
    printf("%s: balance is %d,%02d\n", getCardName(cardKalle), getEuros(getBalance(cardKalle)), getCents(getBalance(cardKalle))); /*Kalle's card: balance is 150.00*/
    payEconomicalFromCard(unicafeExactum, cardKalle);
    printf("%s: balance is %d,%02d\n", getCardName(cardKalle), getEuros(getBalance(cardKalle)), getCents(getBalance(cardKalle))); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %d,%02d\n", getCashRegisterName(unicafeExactum), getEuros(getCashInRegister(unicafeExactum)), getCents(getCashInRegister(unicafeExactum))); /*Unicafe Exactum: balance is 1202.00*/
    return 0;
}
