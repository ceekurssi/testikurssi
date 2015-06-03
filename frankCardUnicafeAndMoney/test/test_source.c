#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/frankCard.h"
#include "../src/cashRegister.h"


START_TEST(test_frank_card)
{
    CashRegister* unicafe;
    FrankCard* cardPekka;
    
    unicafe = newCashRegister("Unicafe");
    cardPekka = newFrankCard("cardPekka");
    ck_assert_msg(strcmp(getCashRegisterName(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", getCashRegisterName(unicafe));
    ck_assert_msg(strcmp(getCardName(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", getCardName(cardPekka));
    ck_assert_msg(getEuros(getCashInRegister(unicafe)) == 1000 && (getCents(getCashInRegister(unicafe))) == 0, "Get cash in register doesn't work. Balance should be 1000,0, but it was %d,%02d", getEuros(getCashInRegister(unicafe)), getCents(getCashInRegister(unicafe)));
    ck_assert_msg(getEuros(getBalance(cardPekka)) == 0 && getCents(getBalance(cardPekka)) == 0, "Get balance doesn't work. Balance should be 0,00, but it was %d,%02d", getEuros(getBalance(cardPekka)), getCents(getBalance(cardPekka)));
    ck_assert_msg(getEconomicalSold(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold(unicafe));
    ck_assert_msg(getGourmetSold(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold(unicafe));
    Money* cashBack = payEconomical(unicafe, newMoney(5, 0));
    ck_assert_msg(getEuros(getCashInRegister(unicafe)) == 1002 && (getCents(getCashInRegister(unicafe))) == 60, "Get cash in register doesn't work. Balance should be 1015,0, but it was %d,%02d", getEuros(getCashInRegister(unicafe)), getCents(getCashInRegister(unicafe)));
    ck_assert_msg(getEuros(cashBack) == 2 && getCents(cashBack) == 40, "Pay Economical doesn't work. When given cash is 5,00, you should get 2,40 back, but it was %d,%02d", getEuros(cashBack), getCents(cashBack));
    cashBack = payGourmet(unicafe, newMoney(5, 00));
    ck_assert_msg(getEuros(cashBack) == 0 && getCents(cashBack) == 60, "Pay Gourmet doesn't work. When given cash is 5,00, you should get 0,60 back, but it was %d,%02d", getEuros(cashBack), getCents(cashBack));
    ck_assert_msg(getEuros(getCashInRegister(unicafe)) == 1007 && (getCents(getCashInRegister(unicafe))) == 0, "Get cash in register doesn't work. Balance should be 1015,0, but it was %d,%02d", getEuros(getCashInRegister(unicafe)), getCents(getCashInRegister(unicafe)));
    cashBack = payEconomical(unicafe, newMoney(2, 00));
    ck_assert_msg(getEuros(cashBack) == 2 && getCents(cashBack) == 0, "Pay Economical doesn't work. When given cash is 2,00, you should get 2,00 back, but it was %d,%02d", getEuros(cashBack), getCents(cashBack));
    cashBack = payGourmet(unicafe, newMoney(4, 00));
    ck_assert_msg(getEuros(cashBack) == 4 && getCents(cashBack) == 0, "Pay Gourmet doesn't work. When given cash is 4,00, you should get 4,00 back, but it was %d,%02d", getEuros(cashBack), getCents(cashBack));
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work.");
    loadMoneyToCard(unicafe, cardPekka, newMoney(8, 00));
    ck_assert_msg(getEuros(getCashInRegister(unicafe)) == 1015 && (getCents(getCashInRegister(unicafe))) == 0, "Get cash in register doesn't work. Balance should be 1015,0, but it was %d,%02d", getEuros(getCashInRegister(unicafe)), getCents(getCashInRegister(unicafe)));
    ck_assert_msg(getEuros(getBalance(cardPekka)) == 8 && getCents(getBalance(cardPekka)) == 0, "Get balance doesn't work. Balance should be 8,00, but it was %d,%02d", getEuros(getBalance(cardPekka)), getCents(getBalance(cardPekka)));
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work.");
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(getEconomicalSold(unicafe) == 2, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold(unicafe));
    ck_assert_msg(getGourmetSold(unicafe) == 2, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold(unicafe));

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
