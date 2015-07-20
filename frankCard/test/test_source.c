#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/frankCard.h"


START_TEST(test_frank_card) {
    FrankCard* cardPekka;
    
    cardPekka = new_FrankCard("cardPekka");
    ck_assert_msg(strcmp(getName_FrankCard(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", getName_FrankCard(cardPekka));
    loadMoney_FrankCard(cardPekka, 7.0);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 7.0) < 0.00001, "Load money doesn't work. Balance should be 7.0, but it was %.2f", getBalance_FrankCard(cardPekka));
    loadMoney_FrankCard(cardPekka, -10.0);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 7.0) < 0.00001, "Load money doesn't work. Balance should be 7.0, but it was %.2f", getBalance_FrankCard(cardPekka));
    loadMoney_FrankCard(cardPekka, 1.0);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 8.0) < 0.00001, "Load money doesn't work. Balance should be 8.0, but it was %.2f", getBalance_FrankCard(cardPekka));
    payGourmet_FrankCard(cardPekka);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 3.6) < 0.00001, "Pay gourmet doesn't work. Balance should be 3.60, but it was %.2f", getBalance_FrankCard(cardPekka));
    payEconomical_FrankCard(cardPekka);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 1.0) < 0.00001, "Pay economical doesn't work. Balance should be 1.00, but it was %.2f", getBalance_FrankCard(cardPekka));
    payGourmet_FrankCard(cardPekka);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 1.0) < 0.00001, "Pay gourmet doesn't work. Balance should be 1.00, but it was %.2f", getBalance_FrankCard(cardPekka));
    loadMoney_FrankCard(cardPekka, 2.0);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 3.0) < 0.00001, "Load money doesn't work. Balance should be 3.00, but it was %.2f", getBalance_FrankCard(cardPekka));
    payEconomical_FrankCard(cardPekka);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 0.4) < 0.00001, "Pay economical doesn't work. Balance should be 0.4, but it was %.2f", getBalance_FrankCard(cardPekka));
    payEconomical_FrankCard(cardPekka);
    ck_assert_msg(fabs(getBalance_FrankCard(cardPekka) - 0.4) < 0.00001, "Pay economical doesn't work. Balance should be 0.4, but it was %.2f", getBalance_FrankCard(cardPekka));
    free_FrankCard(cardPekka);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "9");
	return tmc_run_tests(argc, argv, s);
}
