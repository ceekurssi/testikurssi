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
    
    unicafe = new_CashRegister("Unicafe");
    ck_assert_msg(unicafe != NULL, "new_CashRegister returned NULL");
    cardPekka = new_FrankCard("cardPekka");
    ck_assert_msg(cardPekka != NULL, "new_FrankCard returned NULL");
    ck_assert_msg(strcmp(getName_CashRegister(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", getName_CashRegister(unicafe));
    ck_assert_msg(strcmp(getName_FrankCard(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", getName_FrankCard(cardPekka));
    ck_assert_msg(fabs(getCashInRegister_CashRegister(unicafe) - 1000.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1000.0, but it was %.2f", getCashInRegister_CashRegister(unicafe));
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 0.00) < 0.00001, "Get balance doesn't work. Balance should be 0.00, but it was %.2f", getBalance_FrankCard(cardPekka));
    ck_assert_msg(getEconomicalSold_CashRegister(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold_CashRegister(unicafe));
    ck_assert_msg(getGourmetSold_CashRegister(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold_CashRegister(unicafe));
    double cashBack = payEconomical_CashRegister(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 2.40) < 0.00001, "Pay Economical doesn't work. When given cash is 5.00, you should get 2.40 back, but it was %.2f", cashBack);
    cashBack = payGourmet_CashRegister(unicafe, 5.00);
    ck_assert_msg(fabs(cashBack - 0.60) < 0.00001, "Pay Gourmet doesn't work. When given cash is 5.00, you should get 0.60 back, but it was %.2f", cashBack);
    cashBack = payEconomical_CashRegister(unicafe, 2.00);
    ck_assert_msg(fabs(cashBack - 2.00) < 0.00001, "Pay Economical doesn't work. When given cash is 2.00, you should get 2.00 back, but it was %.2f", cashBack);
    cashBack = payGourmet_CashRegister(unicafe, 4.00);
    ck_assert_msg(fabs(cashBack - 4.00) < 0.00001, "Pay Gourmet doesn't work. When given cash is 4.00, you should get 4.00 back, but it was %.2f", cashBack);
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work. If there isn't enough money, you should return 0.");
    ck_assert_msg(payGourmetFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work. If there isn't enough money, you should return 0.");
    loadMoneyToCard_CashRegister(unicafe, cardPekka, 8.00);
    ck_assert_msg(fabs(getCashInRegister_CashRegister(unicafe) - 1015.0) < 0.00001, "Get cash in register doesn't work. Balance should be 1015.0, but it was %.2f", getCashInRegister_CashRegister(unicafe));
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 8.00) < 0.00001, "Get balance doesn't work. Balance should be 8.00, but it was %.2f", getBalance_FrankCard(cardPekka));
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work. If payment was successful, you should return 1.");
    ck_assert_msg(payGourmetFromCard_CashRegister(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work. If payment was successful, you should return 1.");
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work. You should return 0, when there isn't enough money.");
    if (free_FrankCard(cardPekka) == -1){
        free(cardPekka);
        fail("free_FrankCard should free allocated memory and return 1");
    }
    if (free_CashRegister(unicafe) == -1){
        free(cardPekka);
        fail("free_FrankCard should free allocated memory and return 1");
    }

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
