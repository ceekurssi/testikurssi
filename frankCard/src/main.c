#include <stdio.h>
#include "frankCard.h"

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
