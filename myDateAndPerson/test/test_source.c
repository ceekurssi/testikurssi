#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/person.h"
#include "../src/myDate.h"


START_TEST(test_birthdays)
{
    Person* jukka = newPerson("Jukka", 5, 5, 1995);
    Person* pekka = newPerson("Pekka", 2, 3, 2003);
    ck_assert_msg(olderThan(jukka, pekka) == 1, "Jukka is older than Pekka");
    ck_assert_msg(isAdult(jukka) == 1, "Jukka is an adult");
    ck_assert_msg(isAdult(pekka) == 0, "Pekka isn't an adult");
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_birthdays, "12");
	return tmc_run_tests(argc, argv, s);
}
