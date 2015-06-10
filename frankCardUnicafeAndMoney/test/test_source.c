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
    ck_assert_msg(strcmp(CashRegister_getCashRegisterName(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", CashRegister_getCashRegisterName(unicafe));
    ck_assert_msg(strcmp(FrankCard_getCardName(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", FrankCard_getCardName(cardPekka));
    ck_assert_msg(CashRegister_getCashInRegister(unicafe).euros == 1000 && CashRegister_getCashInRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1000,00, but it was %d,%02d", CashRegister_getCashInRegister(unicafe).euros, CashRegister_getCashInRegister(unicafe).cents);
    ck_assert_msg(FrankCard_getBalance(cardPekka).euros == 0 && FrankCard_getBalance(cardPekka).cents == 0, "Get balance doesn't work. Balance should be 0,00, but it was %d,%02d", FrankCard_getBalance(cardPekka).euros, FrankCard_getBalance(cardPekka).cents);
    ck_assert_msg(CashRegister_getEconomicalSold(unicafe) == 0, "Economical sold doesn't work. Count should be 0, but it was %d", CashRegister_getEconomicalSold(unicafe));
    ck_assert_msg(CashRegister_getGourmetSold(unicafe) == 0, "Gourmet sold doesn't work. Count should be 0, but it was %d", CashRegister_getGourmetSold(unicafe));
    Money cashBack = CashRegister_payEconomical(unicafe, (Money){5, 0});
    ck_assert_msg(CashRegister_getCashInRegister(unicafe).euros == 1002 && CashRegister_getCashInRegister(unicafe).cents == 60, "Get cash in register doesn't work. Balance should be 1015,00, but it was %d,%02d", CashRegister_getCashInRegister(unicafe).euros, CashRegister_getCashInRegister(unicafe).cents);
    ck_assert_msg(cashBack.euros == 2 && cashBack.cents == 40, "Pay Economical doesn't work. When given cash is 5,00, you should get 2,40 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    cashBack = CashRegister_payGourmet(unicafe, (Money){5, 0});
    ck_assert_msg(cashBack.euros == 0 && cashBack.cents == 60, "Pay Gourmet doesn't work. When given cash is 5,00, you should get 0,60 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    ck_assert_msg(CashRegister_getCashInRegister(unicafe).euros == 1007 && CashRegister_getCashInRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1015,0, but it was %d,%02d", CashRegister_getCashInRegister(unicafe).euros, CashRegister_getCashInRegister(unicafe).cents);
    cashBack = CashRegister_payEconomical(unicafe, (Money){2, 00});
    ck_assert_msg(cashBack.euros == 2 && cashBack.cents == 0, "Pay Economical doesn't work. When given cash is 2,00, you should get 2,00 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    cashBack = CashRegister_payGourmet(unicafe, (Money){4, 00});
    ck_assert_msg(cashBack.euros == 4 && cashBack.cents == 0, "Pay Gourmet doesn't work. When given cash is 4,00, you should get 4,00 back, but it was %d,%02d", cashBack.euros, cashBack.cents);
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(CashRegister_payGourmetFromCard(unicafe, cardPekka) == 0, "Pay gourmet from card doesn't work.");
    CashRegister_loadMoneyToCard(unicafe, cardPekka, (Money){8, 00});
    ck_assert_msg(CashRegister_getCashInRegister(unicafe).euros == 1015 && CashRegister_getCashInRegister(unicafe).cents == 0, "Get cash in register doesn't work. Balance should be 1015,00, but it was %d,%02d", CashRegister_getCashInRegister(unicafe).euros, CashRegister_getCashInRegister(unicafe).cents);
    ck_assert_msg(FrankCard_getBalance(cardPekka).euros == 8 && FrankCard_getBalance(cardPekka).cents == 0, "Get balance doesn't work. Balance should be 8,00, but it was %d,%02d", FrankCard_getBalance(cardPekka).euros, FrankCard_getBalance(cardPekka).cents);
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 1, "Pay Economal from card doesn't work.");
    ck_assert_msg(CashRegister_payGourmetFromCard(unicafe, cardPekka) == 1, "Pay gourmet from card doesn't work.");
    ck_assert_msg(CashRegister_payEconomicalFromCard(unicafe, cardPekka) == 0, "Pay Economal from card doesn't work.");
    ck_assert_msg(CashRegister_getEconomicalSold(unicafe) == 2, "Economical sold doesn't work. Count should be 0, but it was %d", CashRegister_getEconomicalSold(unicafe));
    ck_assert_msg(CashRegister_getGourmetSold(unicafe) == 2, "Gourmet sold doesn't work. Count should be 0, but it was %d", CashRegister_getGourmetSold(unicafe));

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_frank_card, "10");
	return tmc_run_tests(argc, argv, s);
}
