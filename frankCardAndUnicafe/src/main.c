#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 5.
 * Copy frankCard.c from previous exercise. 
 * Header cashRegister.h specifies the public interface of cashRegister. 
 * Define a structure called cashRegister in cashRegister.c.
 * CashRegister contains four members, pointer to string name, double for cashInRegister and integers for economicalSold and gourmetSold.
 * CashRegister_new allocate memory for a new cashRegister and set its name to point to a given name. EconomicalSold and gourmetSold are set to 0 and cashInRegister to 1000.
 * CashRegister_getName should return the name of the cashRegister and CashRegister_getCashInRegister should return the balance of the cashRegister.
 * CashRegister_getEconomicalSold should return the number of economical lunches sold and CashRegister_getGourmetSold should return the number of gourmet lunches sold.
 * Function CashRegister_payEconomical should check if the given cash is at least 2.60 and then add the price of the lunch to the register, increase the amount of sold economical lunches and return givenCash - lunch price.
 * If the givenCash is less than 2.60, function should return the whole amount.
 * Function CashRegister_payGourmet should work like CashRegister_payEconomical, but now the price of the lunch is 4.40.
 * Functions CashRegister_payEconomicalFromCard and CashRegister_payGourmetFromCard should check if the balance of the card is at least the price of the lunch and then pay the lunch from the card, increase the amount of sold lunches and return 1 if the lunch was sold and 0 if not.
 * Function CashRegister_loadMoneyToCard should load a positive amount of money to the given frankCard and increase the cashInRegister correspondingly.
 * Function CashRegister_free should free all allocated memory.*/

int main(void) {
    CashRegister* unicafeExactum = new_CashRegister("Unicafe Exactum");
    FrankCard* cardKalle = new_FrankCard("Kalle's card");
    loadMoneyToCard_CashRegister(unicafeExactum, cardKalle, 2.0);
    printf("%s: balance is %.2f\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 2.00*/
    printf("%s: balance is %.2f\n", getName_CashRegister(unicafeExactum), getCashInRegister_CashRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (payGourmetFromCard_CashRegister(unicafeExactum, cardKalle)){
        printf("true\n");
    } else {
        printf("false\n"); /*payment success: false*/
    }
    printf("%s: balance is %.2f\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 2.00*/
    loadMoneyToCard_CashRegister(unicafeExactum, cardKalle, 200.0);
    printf("%s: balance is %.2f\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 150.00*/
    payEconomicalFromCard_CashRegister(unicafeExactum, cardKalle);
    printf("%s: balance is %.2f\n", getCardName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 147.40*/
    printf("%s: balance is %.2f\n", getName_CashRegister(unicafeExactum), getCashInRegister_CashRegister(unicafeExactum)); /*Unicafe Exactum: balance is 1202.00*/
    free_FrankCard(cardKalle);
    free_CashRegister(unicafeExactum);
    return 0;
}
