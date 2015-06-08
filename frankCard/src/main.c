#include <stdio.h>
#include "frankCard.h"

int main()
{
    FrankCard* cardKalle = newFrankCard("Kalle's card");
    FrankCard* cardVille = newFrankCard("Ville's card");
    loadMoney(cardKalle, 20.0);
    loadMoney(cardVille, 15.0);
    printf("%s: balance is %.2f\n", getName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 20.00*/
    printf("%s: balance is %.2f\n", getName(cardVille), getBalance(cardVille)); /*Ville's card: balance is 15.00*/
    payEconomical(cardKalle);
    payGourmet(cardVille);
    printf("%s: balance is %.2f\n", getName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 17.40*/
    printf("%s: balance is %.2f\n", getName(cardVille), getBalance(cardVille)); /*Ville's card: balance is 10.60*/
    loadMoney(cardKalle, 200.0);
    payGourmet(cardVille);
    payEconomical(cardVille);
    printf("%s: balance is %.2f\n", getName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    printf("%s: balance is %.2f\n", getName(cardVille), getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    payGourmet(cardKalle);
    payGourmet(cardVille);
    printf("%s: balance is %.2f\n", getName(cardKalle), getBalance(cardKalle)); /*Kalle's card: balance is 145.60*/
    printf("%s: balance is %.2f\n", getName(cardVille), getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    frankCardFree(cardKalle);
    frankCardFree(cardVille);
    return 0;
}
