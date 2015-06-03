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
    personFree(pekka);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_new_person, "7");
	return tmc_run_tests(argc, argv, s);
}
