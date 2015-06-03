#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/person.h"


START_TEST(test_new_person)
{
    Person* pekka;
    pekka = newPerson("Pekka", 15);
    ck_assert_msg(strcmp(getName(pekka), "Pekka") == 0, "Name should be Pekka, but it was %s", getName(pekka));
    ck_assert_msg(getAge(pekka) == 15, "Age should be 15, but it was %d", getAge(pekka));
    ck_assert_msg(isAdult(pekka) == 0, "IsAdult doesn't work. Pekka isn't an adult");
    Person* jukka; 
    jukka = newPerson("Jukka", -50);
    ck_assert_msg(jukka == NULL, "You should return NULL when trying to create person with negative age");
    jukka = newPerson("Jukka", 50);
    ck_assert_msg(isAdult(jukka) == 1, "Jukka is an adult");
    becomeOlder(pekka);
    ck_assert_msg(getAge(pekka) == 16, "BecomeOlder doesn't work. Age should be 16, but it was %d", getAge(pekka));
    becomeOlder(pekka);
    becomeOlder(pekka);    
    ck_assert_msg(isAdult(pekka) == 1, "IsAdult doesn't work. Pekka is an adult");
    personFree(jukka);
    personFree(pekka);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_new_person, "7.1");
	return tmc_run_tests(argc, argv, s);
}
