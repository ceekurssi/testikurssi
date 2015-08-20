#include <stdio.h>
#include "frankCard.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 4. 
 * Header frankCard.h specifies the public interface of frankCard. 
 * Define a structure called frankCard in frankCard.h. frankCard contains two members, pointer to string name and double balance. 
 * Implement all functions in frankCard.c. 
 * FrankCard_new allocate memory for a new frankCard and set its name to point to a given name. Balance is set to 0.0.
 * FrankCard_new should return a pointer to the allocated FrankCard.
 * FrankCard_getName returns the name of the card and FrankCard_getBalance returns the balance of the card.
 * Function FrankCard_payEconomical should decrease the balance by 2.60 euros and function FrankCard_payGourmet should decrease the balance by 4.40 euros.
 * If there isn't enought money, the balance of the card doesn't change.
 * Function FrankCard_loadMoney should increase the balance of the card by the given amount. It isn't possible to load a negative amount. 
 * If the balance of the card is more than 150 euros, the balance is set to 150 euros.
 * Function FrankCard_free should free all allocated memory and return 1 if successful. */

int main(void) {
    FrankCard* cardKalle = new_FrankCard("Kalle's card");
    FrankCard* cardVille = new_FrankCard("Ville's card");
    loadMoney_FrankCard(cardKalle, 20.0);
    loadMoney_FrankCard(cardVille, 15.0);
    printf("%s: balance is %.2f\n", getName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 20.00*/
    printf("%s: balance is %.2f\n", getName_FrankCard(cardVille), getBalance_FrankCard(cardVille)); /*Ville's card: balance is 15.00*/
    payEconomical_FrankCard(cardKalle);
    payGourmet_FrankCard(cardVille);
    printf("%s: balance is %.2f\n", getName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 17.40*/
    printf("%s: balance is %.2f\n", getName_FrankCard(cardVille), getBalance_FrankCard(cardVille)); /*Ville's card: balance is 10.60*/
    loadMoney_FrankCard(cardKalle, 200.0);
    payGourmet_FrankCard(cardVille);
    payEconomical_FrankCard(cardVille);
    printf("%s: balance is %.2f\n", getName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 150.00*/
    printf("%s: balance is %.2f\n", getName_FrankCard(cardVille), getBalance_FrankCard(cardVille)); /*Ville's card: balance is 3.60*/
    payGourmet_FrankCard(cardKalle);
    payGourmet_FrankCard(cardVille);
    printf("%s: balance is %.2f\n", getName_FrankCard(cardKalle), getBalance_FrankCard(cardKalle)); /*Kalle's card: balance is 145.60*/
    printf("%s: balance is %.2f\n", getName_FrankCard(cardVille), getBalance_FrankCard(cardVille)); /*Ville's card: balance is 3.60*/
    free_FrankCard(cardKalle);
    free_FrankCard(cardVille);
    return 0;
}
