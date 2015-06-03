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
    ck_assert_msg(fabs(getCashInRegister(unicafe) - 1000.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1000.0, but it was %.2f", getCashInRegister(unicafe));
    ck_assert_msg(fabs(getBalance(cardPekka) - 0.00) < 0.00001, "Get balance doesn't work. Balance should be 0.00, but it was %.2f", getBalance(cardPekka));
    ck_assert_msg(getEconomicalSold(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold(unicafe));
    ck_assert_msg(getGourmetSold(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold(unicafe));
    double cashBack = payEconomical(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 2.40) < 0.00001, "Pay Economical doesn't work. When given cash is 5.00, you should get 2.40 back, but it was %.2f", cashBack);
    cashBack = payGourmet(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 0.60) < 0.00001, "Pay Gourmet doesn't work. When given cash is 5.00, you should get 0.60 back, but it was %.2f", cashBack);
    cashBack = payEconomical(unicafe, 2.00);
    ck_assert_msg(fabs(cashBack - 2.00) < 0.00001, "Pay Economical doesn't work. When given cash is 2.00, you should get 2.00 back, but it was %.2f", cashBack);
    cashBack = payGourmet(unicafe, 4.00);
    ck_assert_msg(fabs(cashBack - 4.00) < 0.00001, "Pay Gourmet doesn't work. When given cash is 4.00, you should get 4.00 back, but it was %.2f", cashBack);
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work.");
    loadMoneyToCard(unicafe, cardPekka, 8.00);
    ck_assert_msg(fabs(getCashInRegister(unicafe) - 1015.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1015.0, but it was %.2f", getCashInRegister(unicafe));
    ck_assert_msg(fabs(getBalance(cardPekka) - 8.00) < 0.00001, "Get balance doesn't work. Balance should be 8.00, but it was %.2f", getBalance(cardPekka));
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work.");
    ck_assert_msg(payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
