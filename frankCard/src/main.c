#include <stdio.h>
#include "frankCard.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 4. 
 * Header frankCard.h specifies the public interface of frankCard. 
 * Define a structure called frankCard in frankCard.c. frankCard contains two members, pointer to string name and double balance. 
 * Implement all functions in frankCard.c. 
 * FrankCard_new allocate memory for a new frankCard and set its name to point to a given name. Balance is set to 0.0.
 * FrankCard_getName should return the name of the card and FrankCard_getBalance should return the balance of the card.
 * Function FrankCard_payEconomical should decrease the balance by 2.60 euros and function FrankCard_payGourmet should decrease the balance by 4.40 euros.
 * If there isn't enought money, the balance of the card doesn't change.
 * Function FrankCard_loadMoney should increase the balance of the card by the given amount. It isn't possible to load a negative amount. 
 * If the balance of the card is more than 150 euros, the balance is set to 150 euros.
 * Function FrankCard_free should free all allocated memory. */

int main()
{
    FrankCard* cardKalle = FrankCard_new("Kalle's card");
    FrankCard* cardVille = FrankCard_new("Ville's card");
    FrankCard_loadMoney(cardKalle, 20.0);
    FrankCard_loadMoney(cardVille, 15.0);
    printf("%s: balance is %.2f\n", FrankCard_getName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 20.00*/
    printf("%s: balance is %.2f\n", FrankCard_getName(cardVille), FrankCard_getBalance(cardVille)); /*Ville's card: balance is 15.00*/
    FrankCard_payEconomical(cardKalle);
    FrankCard_payGourmet(cardVille);
    printf("%s: balance is %.2f\n", FrankCard_getName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 17.40*/
    printf("%s: balance is %.2f\n", FrankCard_getName(cardVille), FrankCard_getBalance(cardVille)); /*Ville's card: balance is 10.60*/
    FrankCard_loadMoney(cardKalle, 200.0);
    FrankCard_payGourmet(cardVille);
    FrankCard_payEconomical(cardVille);
    printf("%s: balance is %.2f\n", FrankCard_getName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    printf("%s: balance is %.2f\n", FrankCard_getName(cardVille), FrankCard_getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    FrankCard_payGourmet(cardKalle);
    FrankCard_payGourmet(cardVille);
    printf("%s: balance is %.2f\n", FrankCard_getName(cardKalle), FrankCard_getBalance(cardKalle)); /*Kalle's card: balance is 145.60*/
    printf("%s: balance is %.2f\n", FrankCard_getName(cardVille), FrankCard_getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    FrankCard_free(cardKalle);
    FrankCard_free(cardVille);
    return 0;
}
