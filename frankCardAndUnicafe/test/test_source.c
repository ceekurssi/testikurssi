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
    
    unicafe = CashRegister_new("Unicafe");
    cardPekka = FrankCard_new("cardPekka");
    ck_assert_msg(strcmp(CashRegister_getName(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", CashRegister_getName(unicafe));
    ck_assert_msg(strcmp(FrankCard_getCardName(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", FrankCard_getCardName(cardPekka));
    ck_assert_msg(fabs(CashRegister_getCashInRegister(unicafe) - 1000.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1000.0, but it was %.2f", CashRegister_getCashInRegister(unicafe));
    ck_assert_msg(fabs(FrankCard_getBalance(cardPekka) - 0.00) < 0.00001, "Get balance doesn't work. Balance should be 0.00, but it was %.2f", FrankCard_getBalance(cardPekka));
    ck_assert_msg(CashRegister_getEconomicalSold(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", CashRegister_getEconomicalSold(unicafe));
    ck_assert_msg(CashRegister_getGourmetSold(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", CashRegister_getGourmetSold(unicafe));
    double cashBack = CashRegister_payEconomical(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 2.40) < 0.00001, "Pay Economical doesn't work. When given cash is 5.00, you should get 2.40 back, but it was %.2f", cashBack);
    cashBack = CashRegister_payGourmet(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 0.60) < 0.00001, "Pay Gourmet doesn't work. When given cash is 5.00, you should get 0.60 back, but it was %.2f", cashBack);
    cashBack = CashRegister_payEconomical(unicafe, 2.00);
    ck_assert_msg(fabs(cashBack - 2.00) < 0.00001, "Pay Economical doesn't work. When given cash is 2.00, you should get 2.00 back, but it was %.2f", cashBack);
    cashBack = CashRegister_payGourmet(unicafe, 4.00);
    ck_assert_msg(fabs(cashBack - 4.00) < 0.00001, "Pay Gourmet doesn't work. When given cash is 4.00, you should get 4.00 back, but it was %.2f", cashBack);
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(CashRegister_payGourmetFromCard(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work.");
    CashRegister_loadMoneyToCard(unicafe, cardPekka, 8.00);
    ck_assert_msg(fabs(CashRegister_getCashInRegister(unicafe) - 1015.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1015.0, but it was %.2f", CashRegister_getCashInRegister(unicafe));
    ck_assert_msg(fabs(FrankCard_getBalance(cardPekka) - 8.00) < 0.00001, "Get balance doesn't work. Balance should be 8.00, but it was %.2f", FrankCard_getBalance(cardPekka));
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work.");
    ck_assert_msg(CashRegister_payGourmetFromCard(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work.");
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
