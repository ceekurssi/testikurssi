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
    cardPekka = new_FrankCard("cardPekka");
    ck_assert_msg(strcmp(getCashRegisterName_CashRegister(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", getCashRegisterName_CashRegister(unicafe));
    ck_assert_msg(strcmp(getCardName_FrankCard(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", getCardName_FrankCard(cardPekka));
    ck_assert_msg(getCashInRegister_CashRegister(unicafe).euros == 1000 && getCashInRegister_CashRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1000,00, but it was %d,%02d", getCashInRegister_CashRegister(unicafe).euros, getCashInRegister_CashRegister(unicafe).cents);
    ck_assert_msg(getBalance_FrankCard(cardPekka).euros == 0 && getBalance_FrankCard(cardPekka).cents == 0, "Get balance doesn't work. Balance should be 0,00, but it was %d,%02d", getBalance_FrankCard(cardPekka).euros, getBalance_FrankCard(cardPekka).cents);
    ck_assert_msg(getEconomicalSold_CashRegister(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold_CashRegister(unicafe));
    ck_assert_msg(getGourmetSold_CashRegister(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold_CashRegister(unicafe));
    Money cashBack = payEconomical_CashRegister(unicafe, (Money){5, 0});
    ck_assert_msg(getCashInRegister_CashRegister(unicafe).euros == 1002 && getCashInRegister_CashRegister(unicafe).cents == 60, "Get cash in register doesn't work. Balance should be 1015,00, but it was %d,%02d", getCashInRegister_CashRegister(unicafe).euros, getCashInRegister_CashRegister(unicafe).cents);
    ck_assert_msg(cashBack.euros == 2 && cashBack.cents == 40, "Pay Economical doesn't work. When given cash is 5,00, you should get 2,40 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    cashBack = payGourmet_CashRegister(unicafe, (Money){5, 0});
    ck_assert_msg(cashBack.euros == 0 && cashBack.cents == 60, "Pay Gourmet doesn't work. When given cash is 5,00, you should get 0,60 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    ck_assert_msg(getCashInRegister_CashRegister(unicafe).euros == 1007 && getCashInRegister_CashRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1015,0, but it was %d,%02d", getCashInRegister_CashRegister(unicafe).euros, getCashInRegister_CashRegister(unicafe).cents);
    cashBack = payEconomical_CashRegister(unicafe, (Money){2, 00});
    ck_assert_msg(cashBack.euros == 2 && cashBack.cents == 0, "Pay Economical doesn't work. When given cash is 2,00, you should get 2,00 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    cashBack = payGourmet_CashRegister(unicafe, (Money){4, 00});
    ck_assert_msg(cashBack.euros == 4 && cashBack.cents == 0, "Pay Gourmet doesn't work. When given cash is 4,00, you should get 4,00 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work.");
    loadMoneyToCard_CashRegister(unicafe, cardPekka, (Money){8, 00});
    ck_assert_msg(getCashInRegister_CashRegister(unicafe).euros == 1015 && getCashInRegister_CashRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1015,00, but it was %d,%02d", getCashInRegister_CashRegister(unicafe).euros, getCashInRegister_CashRegister(unicafe).cents);
    ck_assert_msg(getBalance_FrankCard(cardPekka).euros == 8 && getBalance_FrankCard(cardPekka).cents == 0, "Get balance doesn't work. Balance should be 8,00, but it was %d,%02d", getBalance_FrankCard(cardPekka).euros, getBalance_FrankCard(cardPekka).cents);
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work.");
    ck_assert_msg(payGourmetFromCard_CashRegister(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work.");
    ck_assert_msg(payEconomicalFromCard_CashRegister(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(getEconomicalSold_CashRegister(unicafe) == 2, "Economical sold doesn't work. Count should be 0, but it was %d", getEconomicalSold_CashRegister(unicafe));
    ck_assert_msg(getGourmetSold_CashRegister(unicafe) == 2, "Gourmet sold doesn't work. Count should be 0, but it was %d", getGourmetSold_CashRegister(unicafe));

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
